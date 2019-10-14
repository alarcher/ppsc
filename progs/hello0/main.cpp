#include <cstdio>
#include <iostream>

/*
 * This program is a simple demonstration of C++
 */
int print_hello(int i)
{
	// This is a legacy C example
	printf("Hello World! %d\n", i);
	// This is the now-preferred version
	std::cout << "Hello World! " << i << "\n";
	return 0;
}


int main(int argc, char *argv[])
{
	std::cout << "Arg count : " << argc << "\n";
	if (argc<2)
	{
		std::cout << "No argument\n";
		return 1;
	}
	for (int a = 0; a < argc; ++a)
	{
		std::cout << a << ":" << argv[a] << "\n";
	}
	int i = atoi(argv[1]);
	print_hello(i);
	return 0;
}
