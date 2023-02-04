/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:06:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/19 11:50:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Función para montar el array de los "PATHS".
static char	**path_arrayer(t_data *data, char **envp)
{
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
	data->paths_arr = ft_split(tmp, ':');
	ft_free_str((void **)&tmp);
	while (data->paths_arr[i])
	{
		tmp = data->paths_arr[i];
		data->paths_arr[i] = ft_strjoin(data->paths_arr[i], "/");
		free(tmp);
		if (!data->paths_arr)
			ft_free_str((void **)&data->paths_arr);
		i++;
	}
	return (data->paths_arr);
}

// Función de gestión de errores.
static void	error_ctr(t_data *data, int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments.\n", 2);
		exit(1);
	}
	data->in_fd = open(argv[1], O_RDONLY);
	if (data->in_fd < 0)
	{
		ft_putstr_fd("Wrong file.\n", 2);
		exit(1);
	}
	data->out_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->out_fd < 0)
	{
		ft_putstr_fd("Issues opening outfile.\n", 2);
		exit(1);
	}
}

void	leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	atexit(leaks);
	error_ctr(&data, argc, argv);
	if (path_arrayer(&data, envp))
	{
		if (pipe(data.fds) < 0)
		{
			ft_putstr_fd("Error creating pipe.\n", 2);
			exit(1);
		}
		cmd_controller(&data, argv, 2);
		data.cmd1_arr = ft_split(argv[2], ' ');
		cmd_controller(&data, argv, 3);
		data.cmd2_arr = ft_split(argv[3], ' ');
		pipex(&data, envp);
	}
	else
		ft_errexit(&data, "Issues creating PATH array!.\n");
	return (0);
}
