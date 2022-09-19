/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:35:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/19 11:55:58 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_freearr(char	**arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

void	ft_freeyer(t_data *data)
{
	ft_freearr(data->paths_arr);
	ft_free_str((void **)&data->paths_arr);
	ft_freearr(data->cmd1_arr);
	ft_free_str((void **)&data->cmd1_arr);
	ft_freearr(data->cmd2_arr);
	ft_free_str((void **)&data->cmd2_arr);
	free(data->cmd1_path);
	free(data->cmd2_path);
}

//Funciones para encontrar el "path" del comando requerido.
static char	*cmd2_fdr(t_data *data, char **argv, int cmd_pos)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(argv[cmd_pos], ' ');
	if (!cmd)
		ft_errexit(data, "Error spliting commands.\n");
	while (data->paths_arr[i])
	{
		data->cmd2_path = ft_strjoin(data->paths_arr[i], cmd[0]);
		if (!data->cmd2_path)
			return (NULL);
		if (!access(data->cmd2_path, F_OK | X_OK))
		{
			ft_freearr(cmd);
			ft_free_str((void **)&cmd);
			return (data->cmd2_path);
		}
		free(data->cmd2_path);
		i++;
	}
	ft_freearr(cmd);
	ft_free_str((void **)&cmd);
	return (NULL);
}

static char	*cmd1_fdr(t_data *data, char **argv, int cmd_pos)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(argv[cmd_pos], ' ');
	if (!cmd)
		ft_errexit(data, "Error spliting commands.\n");
	while (data->paths_arr[i])
	{
		data->cmd1_path = ft_strjoin(data->paths_arr[i], cmd[0]);
		if (!data->cmd1_path)
			return (NULL);
		if (!access(data->cmd1_path, F_OK | X_OK))
		{
			ft_freearr(cmd);
			ft_free_str((void **)&cmd);
			return (data->cmd1_path);
		}
		free(data->cmd1_path);
		i++;
	}
	ft_freearr(cmd);
	ft_free_str((void **)&cmd);
	return (NULL);
}

void	cmd_controller(t_data *data, char **argv, int cmd_pos)
{
	if (cmd_pos == 2)
	{
		if (!cmd1_fdr(data, argv, cmd_pos))
		{
			ft_putstr_fd(argv[2], 2);
			ft_putstr_fd(": Command not found!\n", 2);
			exit(1);
		}
	}
	else if (cmd_pos == 3)
	{
		if (!cmd2_fdr(data, argv, cmd_pos))
		{
			ft_putstr_fd(argv[3], 2);
			ft_putstr_fd(": Command not found!\n", 2);
			exit(1);
		}
	}
}
