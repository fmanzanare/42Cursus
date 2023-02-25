/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:11 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/25 11:43:32 by fmanzana         ###   ########.fr       */
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
	int		in_fd_flag;
	int		out_fd;
	int		stdin_fd;
	int		stdout_fd;
	int		child1_id;
	int		child2_id;
}				t_data;

void	cmd_controller(t_data *data, char **argv, int cmd_pos);
char	**command_splitter(char *str, char c);
void	ft_free_arr(char **arr);
void	ft_freeyer(t_data *data);
void	ft_errexit(t_data *data, char *str);
void	pipex(t_data *data, char **envp);

#endif
