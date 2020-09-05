#include <color-util/HSL_to_RGB.hpp>
#include <color-util/RGB_to_HSL.hpp>
#include <color-util/RGB_to_XYZ.hpp>
#include <color-util/XYZ_to_RGB.hpp>
#include <color-util/XYZ_to_Lab.hpp>
#include <color-util/Lab_to_XYZ.hpp>
#include <iostream>

#if __cplusplus > 202000L
#include <format>
#define FORMAT(x, ...) std::format(x __VA_OPT__(,) __VA_ARGS__)
#else
#define FORMAT(x, ...) (x)
#endif

int main()
{
    colorutil::RGB rgb_color(200.0 / 255.0, 100.0 / 255.0, 20.0 / 255.0);
    colorutil::XYZ xyz_color = colorutil::convert_RGB_to_XYZ(rgb_color);
    colorutil::Lab lab_color = colorutil::convert_XYZ_to_Lab(xyz_color);
    colorutil::HSL hsl_color = colorutil::convert_RGB_to_HSL(rgb_color);
    double delta;

    std::cout << "sRGB   : " << rgb_color.transpose() << std::endl;
    std::cout << "HSL    : " << hsl_color.transpose() << std::endl;
    std::cout << "CIEXYZ : " << xyz_color.transpose() << std::endl;
    std::cout << "CIELAB : " << lab_color.transpose() << std::endl;

    // Test the correctness of the RGB => HSL => RGB conversion
    if ((delta = (rgb_color - colorutil::convert_HSL_to_RGB(hsl_color)).norm()) > 1e-5)
    {
        throw std::runtime_error(FORMAT("Failed to pass the test (RGB-HSL), delta = {}.", delta));
    }

    // Test the correctness of XYZ => LAB => XYZ
    if ((delta = (xyz_color - colorutil::convert_Lab_to_XYZ(lab_color)).norm()) > 1e-5)
    {
        throw std::runtime_error(FORMAT("Failed to pass the test (XYZ-LAB), delta = {}.", delta));
    }

    // Test the correctness of RGB => XYZ => RGB
    if ((delta = (rgb_color - colorutil::convert_Lab_to_XYZ(xyz_color)).norm()) > 1e-5)
    {
        throw std::runtime_error(FORMAT("Failed to pass the test (RGB-XYZ), delta = {}.", delta));
    }

    return 0;
}
