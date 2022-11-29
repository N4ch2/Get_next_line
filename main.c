#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*aux;

	fd = open("test.txt", O_RDONLY);
	while ((aux = get_next_line(fd)) != NULL)
	{
		printf("%s", aux);
		free(aux);
	}
	close(fd);
}
