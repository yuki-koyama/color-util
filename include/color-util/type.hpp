/// \file type.hpp

#ifndef type_hpp
#define type_hpp

#include <Eigen/Core>

namespace colorutil
{
    /// sRGB - each value is defined in [0, 1]
    using RGB = Eigen::Vector3d;

    /// HSL - each value is defined in [0, 1]
    using HSL = Eigen::Vector3d;

    /// CIEXYZ
    using XYZ = Eigen::Vector3d;

    /// CIELAB
    using Lab = Eigen::Vector3d;
} // namespace colorutil

#endif /* type_hpp */
