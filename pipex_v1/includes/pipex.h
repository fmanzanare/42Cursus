/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:11 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/16 12:58:05 by fmanzana         ###   ########.fr       */
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

char	*cmd_fdr(t_data *data, char **argv, int cmd_pos);
char	*cmd_mkr(t_data *data, char **argv, int cmd_pos);
void	pipex(t_data *data, char **envp);

#endif