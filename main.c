#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *path;

	path = "PATH";
	int fd = open(path, O_RDONLY);
}