/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:35:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/15 19:54:36 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//Funciones para encontrar el "path" del comando requerido.
char	*cmd_fdr(t_data *data, char **argv, int cmd_pos)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = ft_split(argv[cmd_pos], ' ');
	if (!cmd)
	{
		ft_putstr_fd("Error spliting commands.\n", 2);
		exit (1);
	}
	while (data->paths_arr[i])
	{
		cmd_path = ft_strjoin(data->paths_arr[i], cmd[0]);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK | X_OK))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*cmd_mkr(t_data *data, char **argv, int cmd_pos)
{
	char	*cmd_path;

	cmd_path = cmd_fdr(data, argv, cmd_pos);
	if (!cmd_path)
	{
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": Command not found.\n", 2);
		exit(127);
	}
	return (cmd_path);
}
