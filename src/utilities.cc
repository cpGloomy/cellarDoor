#include <ctime>
#include "utilities.h"
#include <sstream>

std::string ThisTime::Get()
{
    std::time_t result = std::time(nullptr);
    return std::asctime(std::localtime(&result));
}

std::string ANSIColour::Colour(std::string cs, TEXTColour cl)
{
    return "\033[" + std::to_string(cl) + "m" + cs + "\033[0m";
}