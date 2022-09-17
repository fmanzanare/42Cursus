/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:11 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/17 11:01:37 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft_plus/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**paths_arr;
	char	**cmd1_arr;
	char	*cmd1_path;
	char	**cmd2_arr;
	char	*cmd2_path;
	int		fds[2];
	int		in_fd;
	int		out_fd;
	int		stdin_fd;
	int		stdout_fd;
	int		child1_id;
	int		child2_id;
}				t_data;

void	cmd_controller(t_data *data, char **argv, int cmd_pos);
void	ft_freeyer(t_data *data);
void	leaks(void);
void	pipex(t_data *data, char **envp);

#endif
