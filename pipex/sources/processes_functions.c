/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:51:00 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/15 18:26:19 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child1(t_data *data, char **envp)
{
	close(data->fds[0]);
	dup2(data->fds[1], 1);
	close(data->fds[1]);
	dup2(data->io_fds[0], 0);
	close(data->io_fds[0]);
	if (execve(data->cmd1_path, data->cmd1_arr, envp) < 0)
	{
		ft_putstr_fd("Command not found!\n", 2);
		exit(1);
	}
}

static void	child2(t_data *data, char **envp)
{
	close(data->fds[1]);
	dup2(data->fds[0], 0);
	close(data->fds[0]);
	dup2(data->io_fds[1], 1);
	close(data->io_fds[1]);
	if (execve(data->cmd2_path, data->cmd2_arr, envp) < 0)
	{
		ft_putstr_fd("Command not found!\n", 2);
		exit(1);
	}
}

static void	parent(t_data *data)
{
	int		exitst;

	close(data->fds[0]);
	close(data->fds[1]);
	waitpid(data->childids[0], NULL, 0);
	waitpid(data->childids[1], &exitst, 0);
	if (WIFEXITED(exitst))
		exit((WEXITSTATUS(exitst)));
	exit(1);
}

void	pipex(t_data *data, char **envp)
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
	data->childids[1] = fork();
	if (data->childids[1] < 0)
	{
		ft_putstr_fd("Failed making second child!\n", 2);
		exit (1);
	}
	else if (data->childids[1] == 0)
		child2(data, envp);
	parent(data);
}
