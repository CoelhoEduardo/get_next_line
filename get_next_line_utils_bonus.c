/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:54:52 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/07/09 23:33:49 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	copy = malloc((unsigned int)len);
	if (copy != NULL)
	{
		while (s[i] != '\0' && i < (len - 1))
		{
			copy[i] = s[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*pointer;
	size_t			max_int;
	size_t			total_size;
	unsigned char	*str;

	max_int = -1;
	if (size != 0 && nmemb > max_int / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	str = (unsigned char *)pointer;
	while (total_size)
	{
		*str++ = 0;
		total_size--;
	}
	return (pointer);
}
