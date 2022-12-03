/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:22:11 by joramire          #+#    #+#             */
/*   Updated: 2022/12/03 19:38:54 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_update(char **remain, char *init)
{
	char	*line;
	char	*new;
	int		i;

	i = 0;
	while ((*remain)[i] != '\n')
		i++;
	line = ft_strlcpy_to_c(*remain, '\n');
	if (line == NULL)
		return (NULL);
	new = ft_strlcpy_to_c(init, '\0');
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

	nbytes = 1;
	while ((ft_strchr((*remain), '\n') == NULL) && nbytes > 0)
	{
		nbytes = read(fd, (*buff), BUFFER_SIZE);
		if (nbytes == -1)
			return (ft_free(remain));
		(*buff)[nbytes] = '\0';
		(*remain) = ft_strlcat(remain, buff, nbytes);
		if ((*remain) == NULL)
			return (NULL);
	}
	if (ft_strchr((*remain), '\n') != NULL)
		line = ft_update(remain, ft_strchr((*remain), '\n') + 1);
	else
	{
		if (((*remain))[0] == '\0')
			return (ft_free(remain));
		line = ft_strlcpy_to_c(((*remain)), '\0');
		ft_free(remain);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*remain[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	else
		line = ft_read(fd, &buff, &remain[fd]);
	if (line == NULL)
		return (ft_free(&buff));
	ft_free(&buff);
	return (line);
}
