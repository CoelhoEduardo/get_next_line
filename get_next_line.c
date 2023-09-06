/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:16:06 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/09/05 22:27:21 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_read(int fd, char **buff)
{
	char	*line;
	int		bytes_read;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	if (!*buff)
	{
		*buff = ft_strdup("");
	}
	bytes_read = 1;
	while (bytes_read && !ft_strchr(*buff, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if ((!*buff && bytes_read == 0) || bytes_read < 0)
		{
			free(*buff);
			return (NULL);
		}
		line[bytes_read] = '\0';
		if (bytes_read < 0)
			break ;
		*buff = ft_strjoin(*buff, line);
	}
	free(line);
	return (*buff);
}

static char	*ft_get_line(char *buff)
{
	char	*line;
	int		bytes_size;

	bytes_size = 0;
	while (buff[bytes_size] && buff[bytes_size] != '\n')
		bytes_size++;
	line = (char *)malloc(sizeof(char) * bytes_size + 2);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(line, buff, bytes_size + 1);
	if (buff[bytes_size] == '\n')
		line[bytes_size++] = '\n';
	line[bytes_size + 1] = '\0';
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
	if (!buff[i] || !buff[i + 1])
		return (NULL);
	i++;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
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
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_get_read(fd, &buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_remove_line(buff);
	if (!line)
	{
		free(line);
		free(buff);
		return (NULL);
	}
	return (line);
}
