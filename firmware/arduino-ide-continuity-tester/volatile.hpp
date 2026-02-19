/*
 * Stuff for working with shared and volatile objects
 */

#ifndef VOLATILE_HPP_
#define VOLATILE_HPP_

#ifdef __AVR_ARCH__
#  include <util/atomic.h>
#  define ATOMIC ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
#else
#  error "Not supported architecture"
#endif

inline void memory_barrier() {
	asm volatile ("" ::: "memory");
}

template<typename T>
inline T atomic_read(const T &x) {
	if (sizeof(x) == 1)
		return x;
	else {
		T t;
		ATOMIC { t = x; }
		return t;
	}
}

template<typename T>
inline void atomic_write(T &x, decltype(T{}) val) {
	if (sizeof(x) == 1)
		x = val;
	else {
		ATOMIC { x = val; }
	}
}

#endif
