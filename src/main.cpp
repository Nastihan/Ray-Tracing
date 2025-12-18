#include <iostream>
#include <print>
#include <ranges>
#include <vector>
#include <fstream>
#include <Vec3.hpp>

auto normalize = [](auto val, auto max) {
    return static_cast<double>(val) / (max - 1);
};

int main() 
{
    unsigned int width = 1280;
    unsigned int height = 1024;

    std::vector<unsigned char> pixels;
    pixels.reserve(width * height * 3);

    for (auto [y, x] : std::views::cartesian_product(std::views::iota(0u, height), std::views::iota(0u, width)))
    {
        if (x == 0) std::println(stderr, "Scanlines remaining: {}", height - y);

        pixels.push_back(static_cast<unsigned char>(255.999 * normalize(x, width)));
        pixels.push_back(static_cast<unsigned char>(255.999 * normalize(y, height)));
        pixels.push_back(0);
    }

    std::ofstream file("image.ppm", std::ios::binary);
    std::println(file, "P6\n{} {}\n255", width, height);
    file.write(reinterpret_cast<char*>(pixels.data()), pixels.size());

    return 0;
}