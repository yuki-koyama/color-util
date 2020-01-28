/// \file type.hpp

#ifndef COLORUTIL_TYPE_HPP
#define COLORUTIL_TYPE_HPP

#include <Eigen/Core>

namespace colorutil
{
    /// RGB - each value is defined in [0, 1]
    using RGB = Eigen::Vector3d;

    /// HSL - each value is defined in [0, 1]
    using HSL = Eigen::Vector3d;

    /// CIEXYZ
    using XYZ = Eigen::Vector3d;

    /// CIELAB
    using Lab = Eigen::Vector3d;
} // namespace colorutil

#endif // COLORUTIL_TYPE_HPP
