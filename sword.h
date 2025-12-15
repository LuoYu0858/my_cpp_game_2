//
// Created by LuoYu on 2025/12/9.
//

#ifndef HOLLOWSAMURAI_SWORD_H
#define HOLLOWSAMURAI_SWORD_H

#include "animation.h"
#include "collision_manager.h"

class Sword {
public:
    Sword(const Vector2& position, bool move_left);
    ~Sword();

    void on_update(float delta);
    void on_render() const;

    bool check_valid() const {
        return is_valid;
    }

private:
    const float SPEED_MOVE = 1250.0f;

private:
    Vector2 position;
    Vector2 velocity;
    Animation animation;
    bool is_valid = true;
    CollisionBox* collision_box = nullptr;
};

#endif //HOLLOWSAMURAI_SWORD_H