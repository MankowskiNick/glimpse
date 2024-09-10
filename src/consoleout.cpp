#include "consoleout.h"

#include <iostream>
#include <string>

ConsoleOut::ConsoleOut() {}
ConsoleOut::~ConsoleOut() {}

void ConsoleOut::Output(const std::string& message, const Glimpse::GLLogStatus status) {
    std::cout << GetGLLogStatusText(status) << " ERROR: " << message << "\n";
}