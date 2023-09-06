/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:15:47 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/09/05 21:22:08 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size <= 0)
	{
		return (ft_strlen(src));
	}
	if (size > 0)
	{
		while (src[len] != '\0' && len < (size - 1))
		{
			dest[len] = src[len];
			len++;
		}
		dest[len] = '\0';
	}
	return (ft_strlen(src));
}
