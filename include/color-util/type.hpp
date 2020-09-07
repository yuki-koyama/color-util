/// \file type.hpp

#ifndef COLORUTIL_TYPE_HPP
#define COLORUTIL_TYPE_HPP

#include <Eigen/Core>

namespace colorutil
{
    /// \brief RGB
    ///
    /// \details Each value is defined in [0, 1].
    class RGB : public Eigen::Vector3d
    {
        using Eigen::Vector3d::Vector3d;
    };

    /// \brief HSL
    ///
    /// \details Each value is defined in [0, 1].
    class HSL : public Eigen::Vector3d
    {
        using Eigen::Vector3d::Vector3d;
    };

    /// \brief CIEXYZ
    class XYZ : public Eigen::Vector3d
    {
        using Eigen::Vector3d::Vector3d;
    };

    /// \brief CIELAB
    class Lab : public Eigen::Vector3d
    {
        using Eigen::Vector3d::Vector3d;
    };
} // namespace colorutil

#endif // COLORUTIL_TYPE_HPP
