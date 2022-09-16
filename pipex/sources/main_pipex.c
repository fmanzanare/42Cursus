/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:06:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/16 12:08:30 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Función para montar el array de los "PATHS".
static char	**path_arrayer(char **envp)
{
	char	**path_str;
	char	*tmp;
	int		i;

	i = 0;
	while (!ft_strnstr(*envp, "PATH=", 5))
	{
		if (!*envp)
			return (0);
		envp++;
	}
	tmp = ft_substr(*envp, 5, ft_strlen(&envp[0][5]));
	if (!tmp)
		return (0);
	path_str = ft_split(tmp, ':');
	ft_free_str((void **)&tmp);
	while (path_str[i])	
	{
		path_str[i] = ft_strjoin(path_str[i], "/");
		if (!path_str)
			ft_free_str((void **)&path_str);
		i++;
	}
	return (path_str);
}

// Función de gestión de errores.
static void	error_ctr(t_data *data, int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments.\n", 2);
		exit(1);
	}
	data->io_fds[0] = open(argv[1], O_RDONLY);
	if (data->io_fds[0] < 0)
	{
		ft_putstr_fd("Wrong file.\n", 2);
		exit(1);
	}
	data->io_fds[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->io_fds[1] < 0)
	{
		ft_putstr_fd("Issues opening outfile.\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	error_ctr(&data, argc, argv);
	data.paths_arr = path_arrayer(envp);
	if (pipe(data.fds) < 0)
	{
		ft_putstr_fd("Error creating pipe.\n", 2);
		exit(1);
	}
	data.cmd1_path = cmd_mkr(&data, argv, 2);
	data.cmd1_arr = ft_split(argv[2], ' ');
	data.cmd2_path = cmd_mkr(&data, argv, 3);
	data.cmd2_arr = ft_split(argv[3], ' ');
	pipex(&data, envp);
	return (0);
}
