
#include "./Log.hpp"
#include "./Time.hpp"

void Parrot::Log::init(const char* filename) {
    this->logFile.open(filename, std::ios::out | std::ios::app);
    this->push(Parrot::getTime(), Parrot::LogType::info);
}

Parrot::Log::Log() {}

Parrot::Log::~Log() {
    this->logFile.close();
}

void Parrot::Log::push(std::string logMsg, Parrot::LogType type) {
    std::string typeName;
    switch (type) {
        case Parrot::LogType::info : typeName = "info"; break;
        case Parrot::LogType::warning : typeName = "warning"; break;
        case Parrot::LogType::error : typeName = "error"; break;
        default: return;
    }
    this->logFile << "[" << typeName << "] " << logMsg << "\n";
}
