#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(const char *s)
{
    size_t  len;
    char    *copy;
    size_t  i;

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

char    *ft_strchr(const char *s, int c)
{
    unsigned char   to_found;

    to_found = (unsigned char)c;
    while(*s && *s != to_found)
    {
        s++;
    }
    if (*s == to_found)
    {
        return ((char *)s);
    }
    else
    {
        return (0);
    }
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    int i;
    int j;

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
