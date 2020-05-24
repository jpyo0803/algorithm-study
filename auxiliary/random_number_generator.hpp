#ifndef ALGORITHM_RNG_HPP
#define ALGORITHM_RNG_HPP

#include <random>

std::random_device rd;
std::mt19937 gen(rd());

template<typename T>
T get_random_number(T lower_limit, T upper_limit) {
    if (std::is_integral<T>::value) {
        std::uniform_int_distribution<> dist(lower_limit, upper_limit);
        return dist(gen);
    } else {
        std::uniform_real_distribution<> dist(lower_limit, upper_limit);
        return dist(gen);
    }
}
#endif //ALGORITHM_RNG_HPP
