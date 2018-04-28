#include <iostream>
#include <color-util/CIEDE2000.hpp>

int main()
{
    const colorutil::Lab color_1(60.2574, -34.0099, 36.2677);
    const colorutil::Lab color_2(60.4626, -34.1751, 39.4387);
    
    constexpr double expected_distance = 1.2644;
    
    std::cout << "Calculated: " << colorutil::calculate_CIEDE2000(color_1, color_2) << std::endl;
    std::cout << "Expected:   " << expected_distance << std::endl;

    return 0;
}
