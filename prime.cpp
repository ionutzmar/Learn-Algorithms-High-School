#include <iostream>
#include <stdlib.h> 

int fu(int arg, char** sarg)
{
	while(arg > 2)
	{
		arg--;
		if(atoi(*sarg) % arg == 0)
			return 0;
	}
	return 1;
}
main(int argc, char* argv[])
{
	std::cout << fu(atoi(argv[1]), &argv[1]);
}