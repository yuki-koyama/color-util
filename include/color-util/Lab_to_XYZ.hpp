/// \file Lab_to_XYZ.hpp

#ifndef COLORUTIL_LAB_TO_XYZ_HPP
#define COLORUTIL_LAB_TO_XYZ_HPP

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    /// \brief Convert a CIELAB color into a CIEXYZ color under Illuminant D65.
    /// \param lab_color A color represented in CIELAB (D65)
    /// \return A color represented in CIEXYZ (D65)
    inline XYZ convert_Lab_to_XYZ(const Lab& lab_color)
    {
        // The reference white point under Illuminant D65
        constexpr double ref_xyz[3] = {95.047, 100.000, 108.883};

        auto finv = [](double t) {
            constexpr double delta = 6.0 / 29.0;

            if (t > delta)
            {
                return std::pow(t, 3.0);
            }
            else
            {
                return 3.0 * delta * delta * (t - 4.0 / 29.0);
            }
        };

        const double l = (lab_color(0) + 16.0) / 116.0;
        const double x = finv(l + lab_color(1) / 500.0);
        const double y = finv(l);
        const double z = finv(l - lab_color(2) / 200.0);

        return Eigen::Vector3d(x, y, z).cwiseProduct(Eigen::Map<const Eigen::Vector3d>(ref_xyz));
    }
} // namespace colorutil

#endif // COLORUTIL_LAB_TO_XYZ_HPP
