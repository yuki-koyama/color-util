/// \file XYZ_to_Lab.hpp

#ifndef XYZ_to_Lab_h
#define XYZ_to_Lab_h

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    /// \brief Convert a CIEXYZ color into a CIELAB color under Illuminant D65.
    /// \param xyz_color A color represented in CIEXYZ
    /// \return A color represented in CIELAB
    inline Lab convert_XYZ_to_Lab(const XYZ& xyz_color)
    {
        // The reference white point under Illuminant D65
        const XYZ reference_xyz(95.047, 100.000, 108.883);

        auto f = [](double t) {
            constexpr double delta = 6.0 / 29.0;
            if (t > delta * delta * delta)
            {
                return std::pow(t, 1.0 / 3.0);
            }
            else
            {
                return t / (3.0 * delta * delta) + 4.0 / 29.0;
            }
        };

        const double x = xyz_color(0) / reference_xyz(0);
        const double y = xyz_color(1) / reference_xyz(1);
        const double z = xyz_color(2) / reference_xyz(2);

        const double L = 116.0 * f(y) - 16.0;
        const double a = 500.0 * (f(x) - f(y));
        const double b = 200.0 * (f(y) - f(z));

        return Lab(L, a, b);
    }
} // namespace colorutil

#endif /* XYZ_to_Lab_h */
