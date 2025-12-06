//
// Created by LuoYu on 2025/12/6.
//

#ifndef HOLLOWSAMURAI_BULLET_TIME_MANAGER_H
#define HOLLOWSAMURAI_BULLET_TIME_MANAGER_H

class BulletTimeManager {
public:
    enum class Status {
        Entering, Exiting
    };

public:
    static BulletTimeManager* instance();

    void post_process() const;
    void set_status(Status status);

    float on_update(float delta);

private:
    BulletTimeManager();
    ~BulletTimeManager();

    // 计算从start到end过渡进度为t时的数值
    static float lerp(float start, float end, float t) {
        return (1 - t) * start + t * end;
    }

private:
    static BulletTimeManager* manager;

private:
    float progress = .0f;                   // 进入子弹时间的进度，0 -> 完全没有进入子弹时间 | 1 -> 完全进入子弹时间
    Status status = Status::Exiting;
    const float SPEED_PROGRESS = 2.0f;
    const float DST_DELTA_FACTOR = .35f;
    const float DST_COLOR_FACTOR = .35f;
};

#endif //HOLLOWSAMURAI_BULLET_TIME_MANAGER_H