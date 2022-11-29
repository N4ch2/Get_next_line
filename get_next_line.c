/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:22:11 by joramire          #+#    #+#             */
/*   Updated: 2022/11/29 22:18:22 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update(char **remain, char *init)
{
	char	*line;
	char	*new;
	int		i;

	i = 0;
	while ((*remain)[i] != '\n')
		i++;
	line = ft_strlcpy_to_c(*remain, '\n', 0);
	if (line == NULL)
		return (NULL);
	new = ft_strlcpy_to_c(init, '\0', 0);
	if (new == NULL)
		return (NULL);
	free(*remain);
	*remain = new;
	return (line);
}

char	*ft_read(int fd, char **buff, char **remain)
{
	int		nbytes;
	char	*line;
	char	*nl;

	nbytes = 1;
	nl = ft_strchr(*remain, '\n');
	while ((nl == NULL) && nbytes > 0)
	{
		nbytes = read(fd, *buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		*buff[nbytes] = '\0';
		*remain = ft_strlcat(remain, buff, nbytes);
		if (*remain == NULL)
			return (NULL);
	}
	nl = ft_strchr(*remain, '\n');
	if (nl != NULL)
	{
		line = ft_update(remain, nl + 1);
		if (line == NULL)
			return (NULL);
	}
	else
	{
		if ((*remain)[0] == '\0')
		{
			*remain = NULL;
			return (NULL);
		}
		line = ft_strlcpy_to_c((*remain), '\0', 1);
		if (line == NULL)
			return (NULL);
		if ((*remain)[0] != '\0')
			free(*remain);
		*remain = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*remain = "";
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	if (remain == NULL)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	else
		line = ft_read(fd, &buff, &remain);
	if (line == NULL)
	{
		if ((remain)[0] != '\0')
			free(remain);
		remain = NULL;
		free(buff);
		buff = NULL;
		return (NULL);
	}
	free(buff);
	buff = NULL;
	return (line);
}
