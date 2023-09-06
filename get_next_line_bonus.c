/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:55:47 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/09/06 17:16:28 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_read(int fd, char **buff)
{
	char	*line;
	char	*aux;
	int		bytes_read;

	line = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!*buff)
		*buff = ft_strdup("");
	bytes_read = 1;
	while (bytes_read && !ft_strchr(*buff, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if ((**buff == '\0' && bytes_read == 0) || bytes_read < 0)
		{
			free(line);
			free(*buff);
			return (NULL);
		}
		line[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		aux = *buff;
		*buff = ft_strjoin(*buff, line);
		free(aux);
	}
	return (free(line), *buff);
}

static char	*ft_get_line(char *buff)
{
	char	*line;
	int		bytes_size;
	int		i;

	bytes_size = 0;
	i = 0;
	while (buff[bytes_size] && buff[bytes_size] != '\n')
		bytes_size++;
	line = ft_calloc((bytes_size + 2), 1);
	while (buff[i] && i < ((bytes_size + 1) - 1))
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[bytes_size] == '\n')
		line[bytes_size++] = '\n';
	line[bytes_size] = '\0';
	return (line);
}

static char	*ft_remove_line(char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0' || buff[i + 1] == '\0')
	{
		free(buff);
		return (NULL);
	}
	i++;
	temp = ft_calloc((ft_strlen(buff) - i + 1), 1);
	if (!temp)
		return (free(buff), free(temp), NULL);
	while (buff[i])
		temp[j++] = buff[i++];
	temp[j] = '\0';
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_get_read(fd, &buff[fd]);
	if (buff[fd] == 0)
		return (NULL);
	line = ft_get_line(&buff[fd][0]);
	buff[fd] = ft_remove_line(&buff[fd][0]);
	return (line);
}
