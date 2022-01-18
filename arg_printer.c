#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define USAGE "./argp format arg\n"

int	main(int argc, char **argv)
{
	if (argc != 3 && argc != 4)
	{
		printf(USAGE);
		return (0);
	}
	if (argc == 4 && argv[3][0] == 'f')
		printf(argv[1], atof(argv[2]));
	else if (isnumber(argv[2][0]))
		printf(argv[1], atoi(argv[2]));
	else
		printf(argv[1], argv[2]);
	return (0);
}
