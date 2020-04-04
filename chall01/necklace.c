/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necklace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:50:23 by fernando          #+#    #+#             */
/*   Updated: 2020/04/04 17:29:53 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != 0)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *dest;

	if(!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		*(dest + i) = *(s1 + i);
	j = -1;
	while (++j < ft_strlen(s2))
		*(dest + i++) = *(s2 + j);
	*(dest + i++) = '\0';
	return (dest);
}

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*src == '\0')
		return ((char*)dest);
	while (dest[i] != '\0' && i < n)
	{
		if (dest[i] == src[0])
		{
			j = 0;
			while (src[j] != '\0' && dest[i + j] == src[j] && (i + j) < n)
			{
				j++;
				if (src[j] == '\0')
					return ((char*)&dest[i]);
			}
		}
		i++;
	}
	return (0);
}

int hv_necklace(char *s1, char *s2)
{
    size_t i;
    size_t len;
	char *aux;
	char *tmp;
	char *tmp2;

    len = ft_strlen(s1);
    if (len != ft_strlen(s2) || (!(aux = malloc(sizeof(char) + len + 1))))
        return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
    i = 0;
    while (s1[i])
    {
        if (ft_strchr(s2, s1[i]))
			i++;
        else
			return (0); 
	}
	tmp = ft_strjoin(s2, s2);
	if (!(tmp2 = ft_strnstr(tmp, s1, ft_strlen(tmp))))
		return (0);
	free(tmp);
	i = -1;
	while (++i < len)
		aux[i] = tmp2[i];
	if (!ft_strcmp(s1, aux))
	{
		free(aux);
		return (1);
	}
	return (0);
}

int main()
{
    printf("%d\n", hv_necklace("nicole", "eniclo"));
	//system("leaks a.out");
    return(0);
}
