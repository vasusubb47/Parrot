#include "./Hash.hpp"

std::string getHex(uint64_t hex) {
	if (hex == 0)
		return "00";
	std::string s = "";
	while (hex) {
		int temp = hex % 16;
		if (temp <= 9)
			s += (48 + temp);
		else
			s += (87 + temp);
		hex = hex / 16;
	}
	reverse(s.begin(), s.end());
	return s;
}

Parrot::ByteArry32<8> Parrot::SHA256(const std::string msg) {

	// Initialize hash values:
	// (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19) :
	uint32_t h[] = {
		0x6a09e667,
		0xbb67ae85,
		0x3c6ef372,
		0xa54ff53a,
		0x510e527f,
		0x9b05688c,
		0x1f83d9ab,
		0x5be0cd19
	};

	// Initialize array of round constants :
	// (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311) :
	uint32_t k[] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};

	// Pre-processing (Padding):

	int zeros = 512 - ((msg.length()*8) + 1 + 64)%512;
	int len = (msg.length()*8) + 1 + zeros + 64;
	std::cout << "len : " << len / 8 << ", zeros : " << zeros << "\n";
	std::vector<byte> msgH = std::vector<byte>(len/8);
	int i;
	for (i = 0; i < msg.length(); i++) {
		msgH[i] = msg[i];
	}
	msgH[i] |= (1 << 7);

	uint64_t mlen = msg.length(), mlenM = 0xff00000000000000;
	int bite = msgH.size() - 8;

	for (int j = 0; j < 8; j++) {
		msgH[bite + j] = (mlen & mlenM);
		// msgH[bite + j] = (uint64_t)(0x1 * (bite + j));
	}
	int c = 1;
	for (int m = 0; m < msgH.size(); m++) {
		std::cout << getHex(msgH[m]);
		if (m % 8 == 0 && m != 0) {
			std::cout << " ";
			c++;
		}
		if (c % 5 == 0) {
			std::cout << "\n";
			c = 1;
		}
	}
	std::string lh = getHex(mlen);
	if (lh.length() != 16) {
		for (int s = lh.length(); s < 16; s++) {
			lh += '0';
		}
	}
	std::cout << "\nlen hex : " << lh << ", " << bite << "\n";
	return Parrot::ByteArry32<8>();
}
