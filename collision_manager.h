//
// Created by LuoYu on 2025/11/29.
//

#ifndef HOLLOWSAMURAI_COLLISION_MANAGER_H
#define HOLLOWSAMURAI_COLLISION_MANAGER_H

#include "collision_box.h"

#include <vector>

class CollisionManager {
public:
    static CollisionManager* instance();

    CollisionBox* create_collision_box();
    void destroy_collision_box(CollisionBox* collision_box);

    void process_collide() const;
    void on_debug_render() const;

private:
    CollisionManager();
    ~CollisionManager();

private:
    static CollisionManager* manager;

    std::vector<CollisionBox*> collision_box_list;  // 碰撞箱管理池
};

#endif //HOLLOWSAMURAI_COLLISION_MANAGER_H