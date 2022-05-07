/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:24:53 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/07 12:15:56 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_fillmem(char **memory, int fd);
void	ft_cleanmem(char **memory);
char	*ft_get_line(char **memory);

char	*get_next_line(int fd)
{
	static char	*memory[256] = {0};
	char		*line;

	if (fd < 0 || fd > 255)
		return (NULL);
	if (ft_fillmem(&memory[fd], fd) == -1)
	{
		free(memory[fd]);
		memory[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(&memory[fd]);
	if (!line)
	{
		free(memory[fd]);
		memory[fd] = NULL;
	}
	return (line);
}

int	ft_fillmem(char **memory, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		value;
	char	*tmp;

	ft_cleanmem(memory);
	value = 1;
	while (!ft_strchr(*memory, '\n') && value)
	{
		value = read(fd, buffer, BUFFER_SIZE);
		if (value < 1)
			return (value);
		buffer[value] = '\0';
		tmp = *memory;
		*memory = ft_strjoin(*memory, buffer);
		free(tmp);
	}
	return (value);
}

void	ft_cleanmem(char **memory)
{
	char	*n_memory;
	int		len;
	int		n_size;

	if (*memory == NULL)
	{
		*memory = (char *)malloc(sizeof(char));
		**memory = '\0';
		return ;
	}
	len = ft_linelen(*memory);
	n_size = ft_strlen(&(*memory)[len]) + 1;
	n_memory = (char *)malloc(sizeof(char) * n_size);
	ft_memcpy(n_memory, &(*memory)[len], n_size);
	free(*memory);
	*memory = n_memory;
}

char	*ft_get_line(char **memory)
{
	char	*line;
	int		len;
	int		i;

	len = ft_linelen(*memory);
	if (len == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		line[i] = (*memory)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
