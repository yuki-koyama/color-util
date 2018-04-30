#include <iostream>
#include <color-util/RGB_to_XYZ.hpp>
#include <color-util/XYZ_to_Lab.hpp>

int main()
{
    colorutil::RGB rgb_color(200.0 / 255.0, 100.0 / 255.0, 20.0 / 200.0);
    colorutil::XYZ xyz_color = colorutil::convert_RGB_to_XYZ(rgb_color);
    colorutil::Lab lab_color = colorutil::convert_XYZ_to_Lab(xyz_color);
    
    std::cout << "sRGB   : " << rgb_color.transpose() << std::endl;
    std::cout << "CIEXYZ : " << xyz_color.transpose() << std::endl;
    std::cout << "CIELAB : " << lab_color.transpose() << std::endl;
    
    return 0;
}
