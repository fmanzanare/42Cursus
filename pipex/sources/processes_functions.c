/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:51:00 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/15 13:52:47 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(char *cmd_path, int io_fds, int fds, char **envp)
{
	int		*fds;

	close(fds[])
}

void	pipex(t_data *data, char **argv, char **envp)
{
	data->stdio_fds[0] = dup(0);
	data->stdio_fds[1] = dup(1);
	data->childids[0] = fork();
	if (data->childids[0] < 0)
	{
		ft_putstr_fd("Failed making first child!\n", 2);
		exit (1);
	}
	else if (data->childids[0] == 0)
		child1(data, envp);
	childis[1] = fork();
	if (childids[1] < 0)
	{
		ft_putstr_fd("Failed making second child!\n", 2);
		exit (1);
	}
	else if (childids[1] == 0)
		child1(argv, fds path_str, envp);
		// ft_secondchild(...);
	// ft_parent(...)
}
