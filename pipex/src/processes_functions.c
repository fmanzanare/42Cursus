/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:51:00 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/12 12:02:50 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_errexit(t_data *data, char *str)
{
	ft_putstr_fd(str, 2);
	ft_freeyer(data);
	exit(1);
}

static void	child1(t_data *data, char **envp)
{
	close(data->fds[0]);
	dup2(data->fds[1], 1);
	close(data->fds[1]);
	dup2(data->in_fd, 0);
	close(data->in_fd);
	if (execve(data->cmd1_path, data->cmd1_arr, envp) < 0)
		ft_errexit(data, "Command not found!\n");
}

static void	child2(t_data *data, char **envp)
{
	waitpid(data->child1_id, NULL, 0);
	close(data->fds[1]);
	dup2(data->fds[0], 0);
	close(data->fds[0]);
	dup2(data->out_fd, 1);
	close(data->out_fd);
	if (execve(data->cmd2_path, data->cmd2_arr, envp) < 0)
		ft_errexit(data, "Command not found!\n");
}

static void	parent(t_data *data)
{
	int		exitst;

	close(data->fds[0]);
	close(data->fds[1]);
	waitpid(data->child1_id, NULL, 0);
	waitpid(data->child2_id, &exitst, 0);
	ft_freeyer(data);
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
		ft_errexit(data, "Failed making first child!\n");
	else if (data->child1_id == 0)
		child1(data, envp);
	data->child2_id = fork();
	if (data->child2_id < 0)
		ft_errexit(data, "Failed making second child!\n");
	else if (data->child2_id == 0)
		child2(data, envp);
	parent(data);
}
