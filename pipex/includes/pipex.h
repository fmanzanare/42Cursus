/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:11 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/15 18:23:10 by fmanzana         ###   ########.fr       */
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
	int		*fds;
	int		*io_fds;
	int		*stdio_fds;
	int		*childids;
}				t_data;

char	*cmd_fdr(t_data *data, char **argv, int cmd_pos);
char	*cmd_mkr(t_data *data, char **argv, int cmd_pos);
void	pipex(t_data *data, char **envp);

#endif
