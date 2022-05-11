/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:33:04 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/11 18:31:48 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fd);
int		ft_fillmem(char **mem, int fd);
void	ft_cleanmem(char **mem);
void	ft_newmemalloc(char **mem);
char	*ft_get_line(char **mem);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
int		ft_linelen(char *ptr);

#endif
