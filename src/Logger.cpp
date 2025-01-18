#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Logger.h"

void Logger::Log(const std::string& message) {
    std::cout << "\033[32m"  // Green color for LOG
              << "LOG | " << CurrentDateTime() << " | " << message
              << "\033[0m"  // Reset color
              << std::endl;
}

void Logger::Err(const std::string& message) {
    std::cerr << "\033[31m"  // Red color for ERR
              << "ERR | " << CurrentDateTime() << " | " << message
              << "\033[0m"  // Reset color
              << std::endl;
}

std::string Logger::CurrentDateTime() {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%y %H:%M:%S");
    return oss.str();
}
