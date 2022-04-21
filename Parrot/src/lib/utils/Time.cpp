
#include "./Time.hpp"

Parrot::TimeIt::TimeIt() {
	start = std::chrono::high_resolution_clock::now();
}

time_t Parrot::TimeIt::getDuration() {
	TimePoint end = std::chrono::high_resolution_clock::now();
	time_t dur = (end.time_since_epoch() - start.time_since_epoch()).count();
	return dur;
}

void Parrot::sleep(uint32_t ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}