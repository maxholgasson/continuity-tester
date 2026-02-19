#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <stddef.h>
#include <stdint.h>

/* Arduino.h defines abs/min/max as macros — undefine to allow templates */
#undef abs
#undef min
#undef max

template<typename T, size_t n>
constexpr size_t size(const T (&)[n]) {
	return n;
}

template<typename T>
inline void set_bits(T &x, decltype(T{}) mask, bool bit) {
	bit ? (x |= mask) : (x &= ~mask);
}

template<typename T>
constexpr T abs(T x) {
	return (x < 0) ? -x : x;
}

template<typename T>
constexpr T min(T x, T y) {
	return (x < y) ? x : y;
}

template<typename T>
constexpr T max(T x, T y) {
	return (x > y) ? x : y;
}

template<typename T>
constexpr T clamp(T x, T low, T high) {
	return (x < low) ? low :
		(x > high) ? high : x;
}

#endif
