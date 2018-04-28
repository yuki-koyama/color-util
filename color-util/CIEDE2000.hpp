#ifndef CIEDE2000_hpp
#define CIEDE2000_hpp

#include <cmath>
#include <color-util/type.hpp>

namespace colorutil
{
    namespace
    {
        constexpr double epsilon = 1e-10;

        inline double my_atan(double y, double x)
        {
            const double value = std::atan2(y, x) * 180.0 / M_PI;
            return (value < 0.0) ? value + 360.0 : value;
        }
    
        inline double my_sin(double x)
        {
            return std::sin(x * M_PI / 180.0);
        }

        inline double get_delta_h_prime(double C_1_prime, double C_2_prime, double h_1_prime, double h_2_prime)
        {
            if (C_1_prime * C_2_prime < epsilon)
            {
                return 0.0;
            }

            const double diff = h_2_prime - h_1_prime;
            
            if (std::abs(diff) <= 180.0)
            {
                return diff;
            }
            else if (diff > 180.0)
            {
                return diff - 360.0;
            }
            else
            {
                return diff + 360.0;
            }
        }
    }
    
    inline double calculate_CIEDE2000(const Lab& color_1, const Lab& color_2)
    {
        const double& L_1 = color_1(0);
        const double& a_1 = color_1(1);
        const double& b_1 = color_1(2);
        const double& L_2 = color_2(0);
        const double& a_2 = color_2(1);
        const double& b_2 = color_2(2);
        
        // Step 1
        
        const double C_1_ab = std::sqrt(a_1 * a_1 + b_1 * b_1);
        const double C_2_ab = std::sqrt(a_2 * a_2 + b_2 * b_2);
        
        const double C_ab_bar = 0.5 * (C_1_ab + C_2_ab);
        
        const double G = 0.5 * (1.0 - std::sqrt(std::pow(C_ab_bar, 7.0) / std::pow(C_ab_bar, 7.0) + std::pow(25.0, 7.0)));
        const double a_1_prime = (1.0 + G) * a_1;
        const double a_2_prime = (1.0 + G) * a_2;
        
        const double C_1_prime = std::sqrt(a_1_prime * a_1_prime + b_1 * b_1);
        const double C_2_prime = std::sqrt(a_2_prime * a_2_prime + b_2 * b_2);
        
        const bool a_prime_and_b_are_zeros_1 = (std::abs(a_1_prime) < epsilon) && (std::abs(b_1) < epsilon);
        const bool a_prime_and_b_are_zeros_2 = (std::abs(a_2_prime) < epsilon) && (std::abs(b_2) < epsilon);
        
        const double h_1_prime = a_prime_and_b_are_zeros_1 ? 0.0 : my_atan(b_1, a_1_prime);
        const double h_2_prime = a_prime_and_b_are_zeros_2 ? 0.0 : my_atan(b_2, a_2_prime);
        
        // Step 2
        
        const double delta_L_prime = L_2 - L_1;
        const double delta_C_prime = C_2_prime - C_1_prime;
        const double delta_h_prime = get_delta_h_prime(C_1_prime, C_2_prime, h_1_prime, h_2_prime);
        const double delta_H_prime = 2.0 * std::sqrt(C_1_prime * C_2_prime) * my_sin(0.5 * delta_h_prime);
        
        // TODO: Step 3

        return 0.0;
    }
}

#endif /* CIEDE2000_hpp */
