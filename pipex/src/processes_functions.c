/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:51:00 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/25 12:18:28 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/**
 * Prints the error string, frees all the allocated memory for data structura
 * and exits with exit code 1.
 * @param *data Pointer to the struct with the info for the whole program
 * @param *str String to be printed.
*/
void	ft_errexit(t_data *data, char *str)
{
	ft_putstr_fd(str, 2);
	ft_freeyer(data);
	exit(1);
}

/**
 * Checks if input file could be openned.
 * Then closes the pipe input fd and duplicates the pipe output fd.
 * Closes the pipe output fd and duplicates the input file fd.
 * Finally, executes the first command.
 * @param *data Pointer to the struct with the info for the whole program
 * @param **envp Environment variables (received on main)
*/
static void	child1(t_data *data, char **envp)
{
	if (data->in_fd_flag)
		exit(0);
	close(data->fds[0]);
	dup2(data->fds[1], 1);
	close(data->fds[1]);
	dup2(data->in_fd, 0);
	execve(data->cmd1_path, data->cmd1_arr, envp);
	exit(127);
}

/**
 * Waits for the child1 process to be finished.
 * Closes the pipe output fd and duplicates the pipe input fd.
 * Closes the pipe input fd and duplicates the output file fd.
 * Finally, executes the second command.
 * @param *data Pointer to the struct with the info for the whole program
 * @param **envp Environment variables (received on main)
*/
static void	child2(t_data *data, char **envp)
{
	waitpid(data->child1_id, NULL, 0);
	close(data->fds[1]);
	dup2(data->fds[0], 0);
	close(data->fds[0]);
	dup2(data->out_fd, 1);
	execve(data->cmd2_path, data->cmd2_arr, envp);
	ft_errexit(data, "Error\n");
}

/**
 * It closes input and output files fds.
 * Then waits the child1 process to be finished.
 * After child1 finishes, it wait for child2 process to be finished.
 * Then, frees all the allocated memory on data structure and exits the program.
 * @param *data Pointer to the struct with the info for the whole program
*/
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

/**
 * First of all, it "dups" the fds 0 and 1.
 * Then creates the first child process and calls "child1" function.
 * Once child1 finishes, it calls "child2" function.
 * Finally, calls the "parent" process function to finish the program.
 * @param *data Pointer to the struct with the info for the whole program
 * @param **envp Environment variables (received on main)
*/
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
