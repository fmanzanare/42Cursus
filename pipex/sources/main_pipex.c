/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:06:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/14 20:17:38 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**path_arrayer(char **envp)
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
		i++;
	}
	return (path_str);
}

void	error_controller(int argc, char **argv, char **envp)
{
	char	**paths_str;
	int		input_fd;
	int		output_fd;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments.\n", 2);
		exit(1);
	}
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 0)
	{
		ft_putstr_fd("Wrong file.\n", 2);
		exit(1);
	}
	output_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		ft_putstr_fd("Issues opening outfile.\n", 2);
		exit(1);	
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths_str;

	error_controller(argc, argv, envp);
	paths_str = path_arrayer(envp);
	// llamar a función PIPEX, con procesos, etc.
	ft_free_str((void**)&paths_str);
	return (0);
}
