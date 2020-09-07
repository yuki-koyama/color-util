/// \file redmean.hpp

#ifndef COLORUTIL_REDMEAN_HPP
#define COLORUTIL_REDMEAN_HPP

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    /// \brief  Calculate a cheap color difference based on redmean.
    /// \param  color_1  The first color. This should be expressed in sRGB color space.
    /// \param  color_2  The second color. This should be expressed in sRGB color space.
    /// \return The color difference of the two colors.
    inline double calculate_redmean(const RGB& color_1, const RGB& color_1)
    {
        double redmean = (color_1(0) + color_2(0)) * 0.5;
        double diff    = color_1 - color_2;
        return sqrt((2 + redmean) * diff(0) + 4 * diff(1) + (2 - redmean) * diff(2));
    }
} // namespace colorutil

#endif // COLORUTIL_REDMEAN_HPP
