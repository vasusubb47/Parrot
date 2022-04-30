
#ifndef LogHpp
#define LogHpp

#include "../import.hpp"

parrot__

enum LogType {
	info,
	warning,
	error
};

class Log {
private:

	std::fstream logFile;

public:

	Log();
	~Log();

	void init(const char* logFileName);
	void push(std::string logMsg, LogType type);

};

__parrot

#endif // !LogHpp

