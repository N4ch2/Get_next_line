/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:00 by joramire          #+#    #+#             */
/*   Updated: 2022/12/02 17:57:39 by joramire         ###   ########.fr       */
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

char	*ft_strlcpy_to_c(char *src, int c, int nl)
{
	size_t	i;
	char	*cpy;

	i = 0;
	while (src[i] != c)
		i++;
	if (nl == 1)
		i++;
	cpy = (char *)malloc(i + 2);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (src[i] != c)
	{
		cpy[i] = src[i];
		i++;
	}
	if (nl == 1)
	{
		cpy[i] = '\n';
		i++;
	}
	cpy[i++] = c;
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strlcat(char **dest, char **sorc, size_t max)
{
	size_t	i;
	size_t	init_size_dst;
	char	*dst;

	if (*sorc == NULL || (*sorc)[0] == '\0')
		return (*dest);
	init_size_dst = ft_strlen(*dest);
	dst = (char *)malloc((ft_strlen(*dest) + ft_strlen(*sorc) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < max && (*sorc)[i] != '\0')
	{
		dst[init_size_dst + i] = (*sorc)[i];
		i++;
	}
	dst[init_size_dst + i] = '\0';
	if ((*dest) != NULL)
		free(*dest);
	return (dst);
}
