#include <clock.h>
#include <iostream>


float deltaTime;
std::chrono::time_point<std::chrono::high_resolution_clock> lastTimeStamp = std::chrono::high_resolution_clock::now() ;


void update_delta_time()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> currentTimeStamp = std::chrono::high_resolution_clock::now();
  	std::chrono::duration<float> delta = currentTimeStamp - lastTimeStamp;
   deltaTime = delta.count(); 
	std::cout << "Delta time " << deltaTime << std::endl;
	lastTimeStamp = currentTimeStamp;
}
