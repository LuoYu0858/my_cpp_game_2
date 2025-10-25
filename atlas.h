//
// Created by LuoYu on 2025/10/25.
//

#ifndef HOLLOWSAMURAI_ATLAS_H
#define HOLLOWSAMURAI_ATLAS_H

#include <vector>
#include <graphics.h>

// 图集类
class Atlas {
public:
    Atlas() = default;
    ~Atlas() = default;

    void load(LPCTSTR path_temp, int num) {
        img_list.clear();
        img_list.resize(num);

        TCHAR path_file[256];
        for (int i = 0; i < num; ++i) {
            _stprintf_s(path_file, path_temp, i + 1);
            loadimage(&img_list[i], path_file);
        }
    }

    void clear() {
        img_list.clear();
    }

    int get_size() const {
        return static_cast<int>(img_list.size());
    }

    IMAGE* get_image(int idx) {
        return idx < 0 or idx >= img_list.size() ? nullptr : &img_list[idx];
    }

    void add_image(const IMAGE& img) {
        img_list.push_back(img);
    }

private:
    std::vector<IMAGE> img_list;    // 图片列表
};

#endif //HOLLOWSAMURAI_ATLAS_H