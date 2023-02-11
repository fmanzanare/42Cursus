/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:35:30 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/11 14:11:21 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
* Function that frees an dimensional array of strings.
*/
void	ft_free_arr(char	**arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
 * Funciton that frees all the allocated memory for "data"
*/
void	ft_freeyer(t_data *data)
{
	ft_free_arr(data->paths_arr);
	ft_free_arr(data->cmd1_arr);
	ft_free_arr(data->cmd2_arr);
	free(data->cmd1_path);
	free(data->cmd2_path);
}

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
			ft_free_arr(cmd);
			return (data->cmd2_path);
		}
		free(data->cmd2_path);
		i++;
	}
	ft_free_arr(cmd);
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
			ft_free_arr(cmd);
			return (data->cmd1_path);
		}
		free(data->cmd1_path);
		i++;
	}
	ft_free_arr(cmd);
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
