//
// Created by LuoYu on 2025/10/25.
//

#ifndef HOLLOWSAMURAI_UTIL_H
#define HOLLOWSAMURAI_UTIL_H

#include <graphics.h>

#pragma comment(lib, "WINMM.lib")
#pragma comment(lib, "MSIMG32.lib")

struct Rect {
    int x, y;   // 矩形左上角坐标
    int w, h;   // 矩形宽高
};

// img -> 需要绘制的图片对象
// rect_dst -> 目标矩形, 源矩形裁剪下来的部分贴附在窗口的哪部分区域
// rect_src -> 源矩形, 在原始图片素材上裁剪的区域, 不需要裁剪时, 源矩形默认为空指针
inline void putimage_ex(IMAGE* img, const Rect* rect_dst, const Rect* rect_src = nullptr) {
    static BLENDFUNCTION blend_func = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    AlphaBlend(GetImageHDC(GetWorkingImage()), rect_dst->x, rect_dst->y, rect_dst->w, rect_dst->h, GetImageHDC(img),
               rect_src ? rect_src->x : 0, rect_src ? rect_src->y : 0, rect_src ? rect_src->w : img->getwidth(),
               rect_src ? rect_src->h : img->getheight(), blend_func);
}

#endif //HOLLOWSAMURAI_UTIL_H