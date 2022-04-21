
#ifndef TimeHpp
#define TimeHpp

#include "../import.hpp"

#define TimePoint std::chrono::steady_clock::time_point

parrot__

struct TimeIt {
	TimePoint start;

	TimeIt();
	time_t getDuration();
};

void sleep(uint32_t = 100);

__parrot

#endif // !TimeHpp
