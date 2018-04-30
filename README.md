# color-util
A header-only C++11 library for handling colors, including color space converters between RGB, XYZ, Lab, etc. and color difference calculators such as CIEDE2000.

## Color Conversions

### RGB-to-XYZ

A sRGB color can be converted to a CIEXYZ color using by `convert_RGB_to_XYZ`. This function is defined in `color-util/RGB_to_XYZ.hpp`.

### XYZ-to-Lab

A CIEXYZ color can be converted to a CIELAB color using by `convert_XYZ_to_Lab`. This function is defined in `color-util/XYZ_to_Lab.hpp`.

## Color Difference Calculators

### CIEDE2000

Given two CIELAB colors, `calculate_CIEDE2000` calculates a *perceptual* difference between these two colors based on a metric called CIEDE2000. This function is defined in `color-util/CIEDE2000.hpp`.

## Dependency

- Eigen <http://eigen.tuxfamily.org/>
