/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:24:53 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/13 12:58:34 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fillmem(char **mem, int fd);
void	ft_cleanmem(char **mem);
void	ft_newmemalloc(char **mem);
char	*ft_get_line(char **mem);

char	*get_next_line(int fd)
{
	static char	*mem[256] = {0};
	char		*line;

	if (fd < 0 || fd > 255)
		return (NULL);
	if (ft_fillmem(&mem[fd], fd) == -1)
	{
		free(mem[fd]);
		mem[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(&mem[fd]);
	if (!line)
	{
		free(mem[fd]);
		mem[fd] = NULL;
	}
	return (line);
}

int	ft_fillmem(char **mem, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		value;
	char	*tmp;

	ft_cleanmem(mem);
	value = 1;
	while (!ft_strchr(*mem, '\n') && value)
	{
		value = read(fd, buffer, BUFFER_SIZE);
		if (value < 1)
			return (value);
		buffer[value] = '\0';
		tmp = *mem;
		*mem = ft_strjoin(*mem, buffer);
		free(tmp);
	}
	return (value);
}

void	ft_cleanmem(char **mem)
{
	if (*mem == NULL)
	{
		*mem = (char *)malloc(sizeof(char));
		**mem = '\0';
		return ;
	}
	ft_newmemalloc(mem);
}

void	ft_newmemalloc(char **mem)
{
	char	*n_mem;
	int		len;
	int		n_size;

	len = ft_linelen(*mem);
	n_size = ft_strlen(&(*mem)[len]) + 1;
	n_mem = (char *)malloc(sizeof(char) * n_size);
	ft_memcpy(n_mem, &(*mem)[len], n_size);
	free(*mem);
	*mem = n_mem;
}

char	*ft_get_line(char **mem)
{
	char	*line;
	int		len;
	int		i;

	len = ft_linelen(*mem);
	if (len == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		line[i] = (*mem)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
