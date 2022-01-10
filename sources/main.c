/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:52:33 by maxperei          #+#    #+#             */
/*   Updated: 2022/01/10 13:53:15 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		//CHILD
		dup2(fd[1],STDOUT_FILENO);
		close(fd[0]);
		join = strjoin(path[i], cmd);
		access(join, X_OK);
		execve();
	}
	waitpid(pid);
	else
	{
		//PARENT
	}
}
