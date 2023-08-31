#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define BUFFER_SIZE 5

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i++;
	temp = (char *)malloc(sizeof(char) * i + 1);
	if (!temp)
	{
		free(str);
		free(temp);
		return (NULL);
	}
	ft_strlcpy(temp, str, i + 1);
	temp[i] = '\0';
	return (temp);
}

char    *ft_get_line(char *buff)
{
    char    *temp;
    char    *bytes_read;
    int nb_bytes;
    int i;

    bytes_read = ft_strchr(buff, '\n');
    nb_bytes = ft_strlen(bytes_read);
    temp = (char *)malloc(sizeof(char) * nb_bytes + 1);
    if (!temp)
    {
        free(buff);
        free(temp);
        return (NULL);
    }
    i = 0;
    while (buff[i] && buff[i] != '\n')
    {
        temp[i] = buff[i];
        i++;
    }
    temp[i + 1] = '\0';
    return (temp);
}

int main()
{
    char *nl;
    char *str = "ola tudo bem ? \nestou bem sim";
    char    *buff = "";
    size_t  i;

    nl = ft_strchr(str, '\n');
    i = (ft_strlen(str) - ft_strlen(nl));
    buff = ft_strdup(nl + 1);


    printf("%s\n", nl);
    printf("%ld\n", i);
    printf("%s\n", buff);
    printf("\n \n%s\n", get_line(str));
    printf("\n \n%s\n", ft_get_line(str));
    return (0);
}