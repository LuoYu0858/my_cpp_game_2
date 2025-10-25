//
// Created by LuoYu on 2025/10/25.
//

#ifndef HOLLOWSAMURAI_TIMER_H
#define HOLLOWSAMURAI_TIMER_H

#include <functional>

// 计时器类
class Timer {
public:
    Timer() = default;
    ~Timer() = default;

    // 重新计时
    void restart() {
        pass_time = 0;
        shotted = false;
    }

    // 设置计时器等待时间
    void set_wait_time(const float val) {
        wait_time = val;
    }

    // 设置计时器是否只触发一次
    void set_one_shot(const bool flag) {
        one_shot = flag;
    }

    // 设置计时器结束后的回调函数
    void set_on_timeout(std::function<void()> on_timeout) {
        this->on_timeout = on_timeout;
    }

    // 暂停计时器
    void pause() {
        paused = true;
    }

    // 恢复计时器
    void resume() {
        paused = false;
    }

    // 计时器帧更新
    void on_update(float delta) {
        // 计时器暂停不更新
        if (paused) return;
        pass_time += delta;
        if (pass_time >= wait_time) {
            bool can_shot = not one_shot or not shotted;
            shotted = true;
            if (can_shot and on_timeout) on_timeout();
            pass_time -= wait_time;
        }
    }

private:
    float pass_time = .0f;              // 已过时间
    float wait_time = .0f;              // 等待时间
    bool paused = false;                // 是否暂停
    bool shotted = false;               // 是否触发
    bool one_shot = false;              // 是否单次触发
    std::function<void()> on_timeout;   // 计时器结束后的回调函数
};

#endif //HOLLOWSAMURAI_TIMER_H