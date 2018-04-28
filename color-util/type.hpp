#ifndef type_hpp
#define type_hpp

#include <Eigen/Core>

namespace colorutil
{
    /// RGB
    using RGB = Eigen::Vector3d;
    
    /// Linearized (inverse companded) RGB
    using rgb = Eigen::Vector3d;
    
    /// CIEXYZ
    using XYZ = Eigen::Vector3d;
    
    /// CIELAB
    using Lab = Eigen::Vector3d;
}

#endif /* type_hpp */
