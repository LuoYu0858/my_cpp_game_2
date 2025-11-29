//
// Created by LuoYu on 2025/11/29.
//

#ifndef HOLLOWSAMURAI_COLLISION_BOX_H
#define HOLLOWSAMURAI_COLLISION_BOX_H

#include "vector2.h"
#include "collision_layer.h"

#include <functional>

class CollisionManager;

class CollisionBox {
    friend class CollisionManager;
private:
    CollisionBox() = default;
    ~CollisionBox() = default;

public:
    void set_enabled(bool flag) {
        enabled = flag;
    }

    void set_layer_src(CollisionLayer layer) {
        layer_src = layer;
    }

    void set_layer_dst(CollisionLayer layer) {
        layer_dst = layer;
    }

    void set_on_collide(std::function<void()> on_collide) {
        this->on_collide = on_collide;
    }

    void set_size(const Vector2& size) {
        this->size = size;
    }

    const Vector2& get_size() const {
        return size;
    }

    void set_position(const Vector2& position) {
        this->position = position;
    }

private:
    Vector2 size;                                       // 矩形碰撞箱尺寸
    Vector2 position;                                   // 矩形碰撞箱中心点位置
    bool enabled = true;                                // 是否开启碰撞
    std::function<void()> on_collide;                   // 碰撞后逻辑
    CollisionLayer layer_src = CollisionLayer::None;    // 当前碰撞箱自身层级
    CollisionLayer layer_dst = CollisionLayer::None;    // 当前碰撞箱目标层级
};

#endif //HOLLOWSAMURAI_COLLISION_BOX_H