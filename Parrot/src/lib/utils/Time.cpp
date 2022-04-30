
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

std::string Parrot::getTime() {
	auto now = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(now);
	std::string time = std::string(std::ctime(&t));
	time[time.size() - 1] = ' ';
	return time;
}