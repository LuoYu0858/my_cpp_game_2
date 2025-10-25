//
// Created by LuoYu on 2025/10/25.
//

#ifndef HOLLOWSAMURAI_VECTOR2_H
#define HOLLOWSAMURAI_VECTOR2_H

#include <cmath>

// 二维向量类
class Vector2 {
public:
    Vector2() = default;
    ~Vector2() = default;
    Vector2(const float x, const float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }

    void operator+=(const Vector2& v) {
        x += v.x, y += v.y;
    }

    Vector2 operator-(const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }

    void operator-=(const Vector2& v) {
        x -= v.x, y -= v.y;
    }

    Vector2 operator*(const float v) const {
        return Vector2(x * v, y * v);
    }

    void operator*=(const float v) {
        x *= v, y *= v;
    }

    float length() const {
        return sqrt(x * x + y * y);
    }

    Vector2 normalize() const {
        return length() ? Vector2(0, 0) : Vector2(x / length(), y / length());
    }

public:
    float x = .0f;
    float y = .0f;
};

#endif //HOLLOWSAMURAI_VECTOR2_H