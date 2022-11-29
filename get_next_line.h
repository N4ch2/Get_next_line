/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:22:06 by joramire          #+#    #+#             */
/*   Updated: 2022/11/29 21:27:33 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif
/*Includes*/
# include	<unistd.h>
# include	<stdlib.h>

/*Main function*/
char	*get_next_line(int fd);

/*Auxiliar functions*/
/*Computes the length of the string s*/
size_t	ft_strlen(const char *s);
/*Locates the first occurrence of c in string s and returns a pointer to it*/
char	*ft_strchr(const char *s, int c);
/*Copies up to dstsize - 1 characters from the string src to dst*/
char	*ft_strlcpy_to_c(char *src, int c, int nl);
/*Appends string src to the end of dst and return a pointer to dst*/
char	*ft_strlcat(char **dst, char **src, size_t dstsize);
#endif