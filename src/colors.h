 /*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: colors.h
@version: I
Creation: 06/07/2023
Last modification: 11/07/2023
*Some parts were made using the AIs Bard and ChatGPT
------------------------------------------------------------------------------*/

#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
constexpr const T& clamp(const T& value, const T& min, const T& max) {
    return (value < min) ? min : ((value > max) ? max : value);
}

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255)
        : r(clamp(red, static_cast<unsigned char>(0), static_cast<unsigned char>(255))),
          g(clamp(green, static_cast<unsigned char>(0), static_cast<unsigned char>(255))),
          b(clamp(blue, static_cast<unsigned char>(0), static_cast<unsigned char>(255))),
          a(clamp(alpha, static_cast<unsigned char>(0), static_cast<unsigned char>(255))) {}

    

    Color operator+(const Color& other) const {
        return Color(
            std::min(static_cast<int>(r) + other.r, 255),
            std::min(static_cast<int>(g) + other.g, 255),
            std::min(static_cast<int>(b) + other.b, 255)
        );
    }

    Color operator*(float factor) const {
        return Color(
            clamp(static_cast<int>(r * factor), 0, 255),
            clamp(static_cast<int>(g * factor), 0, 255),
            clamp(static_cast<int>(b * factor), 0, 255)
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        os << "RGBA(" << static_cast<int>(color.r) << ", "
           << static_cast<int>(color.g) << ", "
           << static_cast<int>(color.b) << ", "
           << static_cast<int>(color.a) << ")";
        return os;
    }

    friend Color operator*(float factor, const Color& color) {
        return color * factor;
    }
};