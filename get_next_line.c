/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:15:16 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/08/31 02:33:36 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *ft_get_read(int fd, char **line_buff)
{
    char    *buff;
    char    *temp;
    int bytes_read;
    
    
	*line_buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    while (ft_strchr(*line_buff, '\n') == NULL && bytes_read != 0)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        buff[bytes_read] = '\0';
        if (bytes_read == -1)
            return (NULL);
        temp = ft_strdup(*line_buff);
        free(buff);
        *line_buff = ft_strjoin(temp, buff);
        free(temp);
        if (ft_strchr(*line_buff, '\n'))
            break;
        bytes_read = read(fd, buff, BUFFER_SIZE);
    }
    return (*line_buff);
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

static char	*clean_s(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	i++;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (free(str), free(tmp), NULL);
	while (str[i] && str[i] != 0)
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}


char	*get_next_line(int fd)
{
	static char    *buff;
    char    *line;
    
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    ft_get_read(fd, &buff);
    if (!buff || !ft_strlen(buff))
        return (NULL);
    line = ft_get_line(buff);
    buff = clean_s(buff);
    if (!line || ft_strlen(line))
    {
        free(line);
        free(buff);
        return (NULL);
    }
    return (line);
}


// int	main(void)
// {
// 	int 	fd;
// 	char	*result = malloc(30);
// 	//int   numbofchars;
// 	fd = open("example.txt", O_RDONLY);
// 	result = get_next_line(fd);
// 	for(int i = 0; i < 5 && result != NULL; i++)
// 	{
// 		printf("%s", result);
// 		result = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
//  }

// int main(void)
// {
//     int fd;
//     char path[] = "example.txt";
//     fd = open(path, O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
    
//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//     }
//     // line = get_next_line(fd);
//     // printf("%s\n", line);

//     close(fd);
//     return 0;
// }



// char    *ft_go_next(char *next_buff)
// {
//     int i;
//     int j;
//     int len;
//     char    *new_buff;

//     i = 0;
//     while (next_buff[i] != '\n' && next_buff[i] != '\0')
//         i++;
//     if (next_buff[i] == '\0')
//     {
//         free(next_buff);
//         return (NULL);
//     }
//     i++;
//     j = i;
//     while (next_buff[i] != '\0')
//         i++;
//     len = i - j + 1;
//     new_buff = (char *) malloc(sizeof(char) * len + 1);
//     if (new_buff == NULL)
//         return (NULL);
//     i = 0;
//     while (1 < len)
//         new_buff[i++] = new_buff[j++];
//     return (new_buff);
// }