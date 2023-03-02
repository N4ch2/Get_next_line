/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:00 by joramire          #+#    #+#             */
/*   Updated: 2022/12/04 15:01:27 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}	
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (s == NULL)
		return (0);
	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_free(char **obj)
{
	if ((*obj) != NULL)
	{
		free((*obj));
		(*obj) = NULL;
	}
	return (NULL);
}

char	*ft_strlcpy_to_c(char **src, int c, char **tofree)
{
	size_t	i;
	char	*cpy;

	i = 0;
	while ((*src)[i] != c)
		i++;
	if (c == '\0')
		i--;
	cpy = (char *)malloc(i + 2);
	if (cpy == NULL)
		return (ft_free(tofree));
	i = 0;
	while ((*src)[i] != c)
	{
		cpy[i] = (*src)[i];
		i++;
	}
	cpy[i] = c;
	if (c == '\n')
		cpy[++i] = '\0';
	return (cpy);
}

char	*ft_strlcat(char **dest, char **sorc, size_t max)
{
	size_t	i;
	size_t	init_size_dst;
	char	*dst;

	if ((*dest) == NULL)
		return (ft_free(dest), ft_strlcpy_to_c(sorc, '\0', sorc));
	init_size_dst = ft_strlen(*dest);
	dst = (char *)malloc((init_size_dst + ft_strlen(*sorc) + 1));
	if (dst == NULL)
		return (ft_free(dest));
	i = 0;
	while ((*dest)[i] != '\0' && i < init_size_dst)
	{
		dst[i] = (*dest)[i];
		i++;
	}
	i = 0;
	while (i < max)
	{
		dst[init_size_dst + i] = (*sorc)[i];
		i++;
	}
	dst[init_size_dst + i] = '\0';
	return (ft_free(dest), dst);
}
