/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipex_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:15:49 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/13 13:28:23 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char	*options[3] = {"env", NULL, NULL};

	(void)argc;
	(void)argv;
	execve("usr/bin/cat", options, envp);
	return (0);
}
