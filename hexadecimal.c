#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned int number;
	scanf("%x", &number);
	printf("%d\n", number);

	int nr;
	scanf("%d", &nr);
	printf("%x\n", nr);
	return 0;
}