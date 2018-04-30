# color-util
A header-only C++11 library for handling colors, including color space converters between RGB, XYZ, Lab, etc. and color difference calculators such as CIEDE2000.

## Color Space Convertors

### RGB-to-XYZ

A sRGB color can be converted to a CIEXYZ color using by `convert_RGB_to_XYZ`. This function is defined in `color-util/RGB_to_XYZ.hpp`.

### XYZ-to-Lab

A CIEXYZ color can be converted to a CIELAB (a.k.a. CIE L\*a\*b\*) color using by `convert_XYZ_to_Lab`. This function is defined in `color-util/XYZ_to_Lab.hpp`.

## Color Difference Calculators

### CIEDE2000

Given two CIELAB colors, `calculate_CIEDE2000` calculates a *perceptual* difference between these two colors based on a metric called CIEDE2000. This function is defined in `color-util/CIEDE2000.hpp`. 

The correctness of the implementation is verified through the test dataset provided by Gaurav Sharma <http://www2.ece.rochester.edu/~gsharma/ciede2000/>.

## Dependency

- Eigen <http://eigen.tuxfamily.org/>

## Installation

color-util is a *header-only* library, so it can be used by just copying the directory named `color-util` to the `include` directory of the target project. No need to build it in advance.

For CMake <https://cmake.org/> users, this repository includes `CMakeLists.txt`; it can be installed by 
```
cmake [PATH_TO_THIS_REPOSITORY] -DCMAKE_INSTALL_PREFIX=[PATH_TO_INSTALL_DIRECTORY]
make install
```
Alternatively, if the target project is also managed by CMake, the `ExternalProject_Add` command is also useful.

## License

MIT License.

## Contribute

Pull requests are welcome.
