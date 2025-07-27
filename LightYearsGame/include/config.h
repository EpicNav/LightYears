#pragma once
#include <string>

std::string GetResourceDir() {
    #ifdef NDEBUG   // Release Build
        return "assets/";
    #else
        return "E:/Unreal Projects/LightYears/LightYearsGame/assets/";
    #endif
}
