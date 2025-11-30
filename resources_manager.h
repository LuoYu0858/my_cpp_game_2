//
// Created by LuoYu on 2025/11/22.
//

#ifndef HOLLOWSAMURAI_RESOURCES_MANAGER_H
#define HOLLOWSAMURAI_RESOURCES_MANAGER_H

#include "atlas.h"

#include <string>
#include <graphics.h>
#include <unordered_map>

// 资源管理器
class ResourceManager {
public:
    static ResourceManager* instance();

    // 加载资源
    void load();

    // 翻转图集
    Atlas* find_atlas(const std::string& id) const;
    // 翻转图片
    IMAGE* find_image(const std::string& id) const;

private:
    static ResourceManager* manager;

    // 图集资源池
    std::unordered_map<std::string, Atlas*> atlas_pool;
    // 图片资源池
    std::unordered_map<std::string, IMAGE*> image_pool;

private:
    ResourceManager();
    ~ResourceManager();

    static void flip_image(IMAGE* src_image, IMAGE* dst_image, int num_h = 1);
    void flip_image(const std::string& src_id, const std::string& dst_id, int num_h = 1);
    void flip_atlas(const std::string& src_id, const std::string& dst_id);
};

#endif //HOLLOWSAMURAI_RESOURCES_MANAGER_H