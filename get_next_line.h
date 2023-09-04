#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif