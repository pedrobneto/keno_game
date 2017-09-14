#include <iostream>

// Return random integer between low and high
int randInt (int low, int high)
{ 
	return low + (rand() % high);
}

int main() {
	// same 10 numbers in all executions
	srand(3);
	for (auto i(0); i < 10; ++i)
		std::cout << randInt(1, 3) << " ";
	std::cout << std::endl << std::endl;

	// different 10 numbers in each execution
	srand((int) time(NULL));
	for (auto i(0); i < 10; ++i)
		std::cout << randInt(1, 3) << " ";
	std::cout << std::endl << std::endl;

	// 3 equal lines, changes in each execution
	for(auto i(0); i < 3; ++i)
	{
		srand((int) time(NULL));
		for(auto j(0); j < 10; ++j) {
			std::cout << randInt(1, 3) << " ";
		}
		std::cout << std::endl;
	}

    return 0;
}