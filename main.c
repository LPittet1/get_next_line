#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *path;
	char *line;

	path = "test.txt";
	int fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	printf("first line : %s", line);
	// line = get_next_line(fd);
	// printf("second line : %s", line);
}