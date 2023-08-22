/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:15:16 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/08/22 19:45:12 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 5000

char    *get_line(char *buff)
{
    int i;

    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
    {
        i++;
    }

    if (buff[i] == '\n')
    {
        buff[i] = '\0';
    }
    else if (buff[i] == '\0')
    {
        return NULL;
    }
    return (buff);
}

char	*get_next_line(int fd)
{
	static char    buff[BUFF_SIZE];
    size_t  bytes_read;

    bytes_read = read(fd, buff, BUFF_SIZE);

    if (bytes_read <= 0)
        return NULL;
    
    get_line(buff);
	return buff;
}

int main(void)
{
    int fd;
    char path[] = "/nfs/homes/ecoelho-/Documents/example.txt";
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
    }

    close(fd);
    return 0;
}

