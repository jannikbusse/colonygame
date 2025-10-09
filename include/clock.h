#pragma once


#include <chrono>

extern float deltaTime;

extern std::chrono::time_point<std::chrono::high_resolution_clock> lastTimeStamp;


void update_delta_time();
