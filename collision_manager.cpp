//
// Created by LuoYu on 2025/11/29.
//

#include "collision_manager.h"

#include <graphics.h>

CollisionManager* CollisionManager::manager = nullptr;

CollisionManager* CollisionManager::instance() {
    if (not manager) manager = new CollisionManager;
    return manager;
}

CollisionBox* CollisionManager::create_collision_box() {
    auto collision_box = new CollisionBox();
    collision_box_list.push_back(collision_box);
    return collision_box;
}

void CollisionManager::destroy_collision_box(CollisionBox* collision_box) {
    std::erase(collision_box_list, collision_box);
    delete collision_box;
}

void CollisionManager::process_collide() const {
    for (CollisionBox* collision_box_src : collision_box_list) {
        // 检测是否启用碰撞，并且目标层级不为空
        if (not collision_box_src->enabled or collision_box_src->layer_dst == CollisionLayer::None) continue;
        for (CollisionBox* collision_box_dst : collision_box_list) {
            if (not collision_box_dst->enabled or
                collision_box_src == collision_box_dst or
                collision_box_src->layer_dst != collision_box_dst->layer_src)
                continue;
            bool is_collide_x =
                    max(
                        collision_box_src->position.x + collision_box_src->size.x / 2,
                        collision_box_dst->position.x + collision_box_dst->size.x / 2
                    ) - min(
                        collision_box_src->position.x - collision_box_src->size.x / 2,
                        collision_box_dst->position.x - collision_box_dst->size.x / 2
                    ) <= collision_box_src->size.x + collision_box_dst->size.x;
            bool is_collide_y =
                    max(
                        collision_box_src->position.y + collision_box_src->size.y / 2,
                        collision_box_dst->position.y + collision_box_dst->size.y / 2
                    ) - min(
                        collision_box_src->position.y - collision_box_src->size.y / 2,
                        collision_box_dst->position.y - collision_box_dst->size.y / 2
                    ) <= collision_box_src->size.y + collision_box_dst->size.y;
            if (is_collide_x and is_collide_y and collision_box_dst->on_collide) collision_box_dst->on_collide();
        }
    }
}

void CollisionManager::on_debug_render() const {
    for (CollisionBox* collision_box : collision_box_list) {
        setlinecolor(collision_box->enabled ? RGB(255, 195, 195) : RGB(115, 115, 175));
        rectangle(
            static_cast<int>(collision_box->position.x - collision_box->size.x / 2),
            static_cast<int>(collision_box->position.y - collision_box->size.y / 2),
            static_cast<int>(collision_box->position.x + collision_box->size.x / 2),
            static_cast<int>(collision_box->position.y + collision_box->size.y / 2)
        );
    }
}

CollisionManager::CollisionManager() = default;

CollisionManager::~CollisionManager() = default;