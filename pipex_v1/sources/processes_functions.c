/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:51:00 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/16 15:15:50 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child1(t_data *data, char **envp)
{
	close(data->fds[0]);
	dup2(data->fds[1], 1);
	close(data->fds[1]);
	dup2(data->in_fd, 0);
	close(data->in_fd);
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
	dup2(data->out_fd, 1);
	close(data->out_fd);
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
	waitpid(data->child1_id, NULL, 0);
	waitpid(data->child2_id, &exitst, 0);
	if (WIFEXITED(exitst))
		exit((WEXITSTATUS(exitst)));
	exit(1);
}

void	pipex(t_data *data, char **envp)
{
	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
	data->child1_id = fork();
	if (data->child1_id < 0)
	{
		ft_putstr_fd("Failed making first child!\n", 2);
		exit (1);
	}
	else if (data->child1_id == 0)
		child1(data, envp);
	data->child2_id = fork();
	if (data->child2_id < 0)
	{
		ft_putstr_fd("Failed making second child!\n", 2);
		exit (1);
	}
	else if (data->child2_id == 0)
		child2(data, envp);
	parent(data);
}
