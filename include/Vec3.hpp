#pragma once

#include <cmath>
#include <format>
#include <concepts>

template<std::floating_point T>
struct Vec3 {
    T x{}, y{}, z{};

    constexpr Vec3() = default;
    constexpr Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    constexpr T& operator[](size_t i) 
    {
        if(i > 2)
        {
            throw std::out_of_range("Index out of range for Vec3");
        }
        return (i == 0) ? x : (i == 1) ? y : z;
    }

    constexpr const T& operator[](size_t i) const 
    {
        if(i > 2)
        {
            throw std::out_of_range("Index out of range for Vec3");
        }
        return (i == 0) ? x : (i == 1) ? y : z;
    }

    constexpr Vec3& operator+=(const Vec3& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    constexpr Vec3& operator*=(T t) {
        x *= t; y *= t; z *= t;
        return *this;
    }

    constexpr T lengthSquared() const {
        return x * x + y * y + z * z;
    }

    T length() const {
        return std::sqrt(lengthSquared());
    }
};

template<typename T>
constexpr Vec3<T> operator+(const Vec3<T>& u, const Vec3<T>& v) {
    return {u.x + v.x, u.y + v.y, u.z + v.z};
}

template<typename T>
constexpr Vec3<T> operator-(const Vec3<T>& u, const Vec3<T>& v) {
    return {u.x - v.x, u.y - v.y, u.z - v.z};
}

template<typename T>
constexpr Vec3<T> operator*(const Vec3<T>& v, T t) {
    return {v.x * t, v.y * t, v.z * t};
}

template<typename T>
constexpr Vec3<T> operator*(T t, const Vec3<T>& v) {
    return v * t;
}

template<typename T>
constexpr Vec3<T> operator/(const Vec3<T>& v, T t) {
    return v * (1 / t);
}

template<typename T>
constexpr T dot(const Vec3<T>& u, const Vec3<T>& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

template<typename T>
constexpr Vec3<T> cross(const Vec3<T>& u, const Vec3<T>& v) {
    return {u.y * v.z - u.z * v.y,
            u.z * v.x - u.x * v.z,
            u.x * v.y - u.y * v.x};
}

template<typename T>
Vec3<T> unitVector(const Vec3<T>& v) {
    return v / v.length();
}

using Point3 = Vec3<double>;
using Color = Vec3<double>;
using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;

template<typename T>
struct std::formatter<Vec3<T>> : std::formatter<std::string> {
    auto format(const Vec3<T>& v, format_context& ctx) const {
        return std::format_to(ctx.out(), "({}, {}, {})", v.x, v.y, v.z);
    }
};