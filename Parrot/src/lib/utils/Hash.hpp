
#ifndef HashHpp
#define HashHpp

#include "../import.hpp"

parrot__

template <int len>
struct ByteArry32 {
	uint32_t arr[len];
};

ByteArry32<8> SHA256(const std::string);

__parrot

#endif // !HashHpp
