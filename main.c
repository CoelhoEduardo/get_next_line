#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int    main(void)
{
    int        fd;
    int        fd_two;
    int        index;
    char    *gnl;

    fd = open("example.txt", O_RDONLY);
    fd_two = open("example.txt", O_RDONLY);
    index = 9;
    while (index--)
    {
        gnl = get_next_line(fd);
        if (gnl)
            printf("%s", gnl);
        free(gnl);
    }
    close(fd);
    return (0);
}