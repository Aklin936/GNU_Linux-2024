#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N = (argc == 2) ? atoi(argv[1]) : atoi(argv[2]);
	int M = (argc == 2) ? 0 : atoi(argv[1]);
	int S = (argc == 4) ? atoi(argv[3]) : 1;

	return 0;
}