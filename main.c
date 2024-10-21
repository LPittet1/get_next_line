#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *path;
	char *line;
	int i = 0;

	path = "test.txt";
	int fd = open(path, O_RDONLY);
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("line %i: %s", i +1, line);
		i++;
	}
}