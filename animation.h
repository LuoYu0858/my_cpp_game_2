//
// Created by LuoYu on 2025/10/25.
//

#ifndef HOLLOWSAMURAI_ANIMATION_H
#define HOLLOWSAMURAI_ANIMATION_H

#include "util.h"
#include "timer.h"
#include "atlas.h"
#include "vector2.h"

#include <vector>
#include <functional>

// 动画类
class Animation {
public:
    // 锚点类型
    enum class AnchorMode {
        Centered,       // 居中
        BottomCentered  // 底部居中
    };

public:
    Animation() {
        timer.set_one_shot(false);
        timer.set_on_timeout([&] {
            // 计时器触发后累加帧索引到下一帧
            ++idx_frame;
            // 是否到达动画列表尾部
            if (idx_frame >= frame_list.size()) {
                // 当前动画是否循环播放，是则从0索引重新播放，否则定格在最后一帧
                idx_frame = is_loop ? 0 : frame_list.size() - 1;
                // 动画已经播放完毕且不能循环播放，调用回调函数
                if (not is_loop and on_finished) on_finished();
            }
        });
    }

    ~Animation() {
    }

    void reset() {
        timer.restart();
        idx_frame = 0;
    }

    void set_anchor_mode(AnchorMode mode) {
        anchor_mode = mode;
    }

    void set_position(const Vector2& position) {
        this->position = position;
    }

    void set_loop(bool flag) {
        is_loop = flag;
    }

    void set_interval(float interval) {
        timer.set_wait_time(interval);
    }

    void set_on_finished(std::function<void()> on_finished) {
        this->on_finished = on_finished;
    }

    // 添加长条形图片作为动画
    // num_h -> 当前图片素材需要被平均切分为几帧显示
    void add_frame(IMAGE* image, int num_h) {
        int width = image->getwidth(), height = image->getheight();
        int width_frame = width / num_h;
        for (int i = 0; i < num_h; ++i) {
            Rect rect_src;
            rect_src.x = i * width_frame, rect_src.y = 0, rect_src.w = width_frame, rect_src.h = height;
            frame_list.emplace_back(image, rect_src);
        }
    }

    // 添加图集类图片作为动画
    void add_frame(Atlas* atlas) {
        for (int i = 0; i < atlas->get_size(); ++i) {
            IMAGE* image = atlas->get_image(i);
            int width = image->getwidth(), height = image->getheight();

            Rect rect_src;
            rect_src.x = 0, rect_src.y = 0, rect_src.w = width, rect_src.h = height;

            frame_list.emplace_back(image, rect_src);
        }
    }

    // 动画帧更新
    void on_update(float delta) {
        timer.on_update(delta);
    }

    // 动画渲染
    void on_render() const {
        const Frame& frame = frame_list[idx_frame];
        Rect rect_dst;
        rect_dst.x = static_cast<int>(position.x) - frame.rect_src.w / 2;
        // 根据动画锚点位置，计算得到目标矩形的位置
        rect_dst.y = anchor_mode == AnchorMode::Centered
                         ? static_cast<int>(position.y) - frame.rect_src.h / 2
                         : static_cast<int>(position.y) - frame.rect_src.h;
        rect_dst.w = frame.rect_src.w, rect_dst.h = frame.rect_src.h;

        putimage_ex(frame.image, &rect_dst, &frame.rect_src);
    }

private:
    // 动画帧
    struct Frame {
        Rect rect_src;
        IMAGE* image = nullptr;

        Frame() = default;
        Frame(IMAGE* image, const Rect& rect_src) : rect_src(rect_src), image(image) {}
        ~Frame() = default;
    };

private:
    Timer timer;                                    // 动画计时器
    Vector2 position;                               // 动画渲染位置
    bool is_loop = true;                            // 动画是否循环
    size_t idx_frame = 0;                           // 当前动画帧索引
    std::vector<Frame> frame_list;                  // 动画帧的序列
    std::function<void()> on_finished;              // 动画播放回调函数
    AnchorMode anchor_mode = AnchorMode::Centered;  // 锚点类型默认居中锚点
};

#endif //HOLLOWSAMURAI_ANIMATION_H