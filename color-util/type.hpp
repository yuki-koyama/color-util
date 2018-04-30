#ifndef type_hpp
#define type_hpp

#include <Eigen/Core>

namespace colorutil
{
    /// sRGB
    using RGB = Eigen::Vector3d;
    
    /// CIEXYZ
    using XYZ = Eigen::Vector3d;
    
    /// CIELAB
    using Lab = Eigen::Vector3d;
}

#endif /* type_hpp */
