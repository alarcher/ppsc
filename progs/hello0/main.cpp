#include <cstdio>
#include <iostream>

/*
 * This program is a simple demonstration of C++
 */

int main()
{
	int i = 42;
	// This is a legacy C example
	printf("Hello World! %d\n", i);
	// This is the now-preferred version
	std::cout << "Hello World! " << i << "\n";
	return 0;
}
