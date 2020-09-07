#include <color-util/HSL_to_RGB.hpp>
#include <color-util/Lab_to_XYZ.hpp>
#include <color-util/RGB_to_HSL.hpp>
#include <color-util/RGB_to_XYZ.hpp>
#include <color-util/XYZ_to_Lab.hpp>
#include <color-util/XYZ_to_RGB.hpp>
#include <iostream>

#if __cplusplus > 202000L
#include <format>
#define FORMAT(x, ...) std::format(x __VA_OPT__(, ) __VA_ARGS__)
#else
#define FORMAT(x, y) (std::string(x) + " ({} = " + std::to_string(y) + ")")
#endif

int main()
{
    const colorutil::RGB rgb_color(200.0 / 255.0, 100.0 / 255.0, 20.0 / 255.0);
    const colorutil::XYZ xyz_color = colorutil::convert_RGB_to_XYZ(rgb_color);
    const colorutil::Lab lab_color = colorutil::convert_XYZ_to_Lab(xyz_color);
    const colorutil::HSL hsl_color = colorutil::convert_RGB_to_HSL(rgb_color);

    std::cout << "sRGB   : " << rgb_color.transpose() << std::endl;
    std::cout << "HSL    : " << hsl_color.transpose() << std::endl;
    std::cout << "CIEXYZ : " << xyz_color.transpose() << std::endl;
    std::cout << "CIELAB : " << lab_color.transpose() << std::endl;

    double delta;

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
    if ((delta = (rgb_color - colorutil::convert_XYZ_to_RGB(xyz_color)).norm()) > 1e-5)
    {
        throw std::runtime_error(FORMAT("Failed to pass the test (RGB-XYZ), delta = {}.", delta));
    }

    return 0;
}
