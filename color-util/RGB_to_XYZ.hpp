/// \file RGB_to_XYZ.hpp

#ifndef RGB_to_XYZ_h
#define RGB_to_XYZ_h

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    /// \param rgb_color A color represented in sRGB
    /// \return A color represented in CIEXYZ
    inline XYZ convert_RGB_to_XYZ(const RGB& rgb_color)
    {
        // Inverse companding for sRGB
        Eigen::Vector3d linearized_rgb_color;
        for (int i : { 0, 1, 2 })
        {
            linearized_rgb_color(i) = (rgb_color(i) <= 0.04045) ? rgb_color(i) / 12.92 : std::pow((rgb_color(i) + 0.055) / 1.055, 2.4);
        }
        
        // Retrieved from http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html
        const Eigen::MatrixXd M = (Eigen::Matrix3d() <<
                                   0.4124564, 0.3575761, 0.1804375,
                                   0.2126729, 0.7151522, 0.0721750,
                                   0.0193339, 0.1191920, 0.9503041
                                   ).finished();
        
        return 100.0 * M * linearized_rgb_color;
    }
}

#endif /* RGB_to_XYZ_h */
