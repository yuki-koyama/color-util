/// \file XYZ_to_RGB.hpp
#ifndef COLORUTIL_XYZ_TO_RGB_HPP
#define COLORUTIL_XYZ_TO_RGB_HPP

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    /// \brief Perform the gamma companding for a sRGB color
    /// \details http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html
    inline RGB sRGB_companding(const RGB& linear_srgb_color)
    {
        RGB srgb_color;
        for (int i : {0, 1, 2})
        {
            srgb_color(i) = (linear_srgb_color(i) <= 0.0031308)
                                ? linear_srgb_color(i) * 12.92
                                : std::pow((linear_srgb_color(i) - 0.055) * 1.055, 1 / 2.4);
        }
        return srgb_color;
    }

    /// \param xyz_color A color represented in CIEXYZ (D65)
    /// \return A color represented in sRGB, unclipped (D65)
    inline XYZ convert_XYZ_to_RGB(const XYZ& xyz_color)
    {
        // Retrieved from http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html
        // sRGB (D65)
        constexpr double M_data[3 * 3] = {
            3.2404542, -1.5371385, -0.4985314, -0.9692660, 1.8760108, 0.0415560, 0.0556434, -0.2040259, 1.0572252};

        // Note: The use of "auto" avoids unnecessary data copy by lazy evaluation
        const auto M = Eigen::Map<const Eigen::Matrix<double, 3, 3, Eigen::RowMajor>>(M_data);

        // Inverse companding for sRGB
        const RGB linear_srgb = (M * xyz_color) / 100.0;

        return sRGB_companding(linear_srgb);
    }
} // namespace colorutil

#endif // COLORUTIL_XYZ_TO_RGB_HPP
