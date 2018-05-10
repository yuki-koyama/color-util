#include <iostream>
#include <color-util/RGB_to_XYZ.hpp>
#include <color-util/XYZ_to_Lab.hpp>
#include <color-util/RGB_to_HSL.hpp>

int main()
{
    colorutil::RGB rgb_color(200.0 / 255.0, 100.0 / 255.0, 20.0 / 200.0);
    colorutil::XYZ xyz_color = colorutil::convert_RGB_to_XYZ(rgb_color);
    colorutil::Lab lab_color = colorutil::convert_XYZ_to_Lab(xyz_color);
    colorutil::HSL hsl_color = colorutil::convert_RGB_to_HSL(rgb_color);
    
    std::cout << "sRGB   : " << rgb_color.transpose() << std::endl;
    std::cout << "HSL    : " << hsl_color.transpose() << std::endl;
    std::cout << "CIEXYZ : " << xyz_color.transpose() << std::endl;
    std::cout << "CIELAB : " << lab_color.transpose() << std::endl;
    
    return 0;
}
