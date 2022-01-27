/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:52:33 by maxperei          #+#    #+#             */
/*   Updated: 2022/01/27 16:00:20 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	char	*check_access(char *cmd, char **env_path)
{
	int		i;
	int		valid_exec;
	char	*full_path;

	i = -1;
	valid_exec = -1;
	while (valid_exec == -1)
	{
		i++;
		full_path = path_join(env_path[i], cmd);
		valid_exec = access(full_path, X_OK);
		if (valid_exec == -1 && full_path)
			free(full_path);
	}
	if (valid_exec == 0)
		return (full_path);
	else
		return (NULL);
}

static	char	**find_paths(char **envp)
{
	char	*path;
	char	**split_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5))
			i++;
		else
		{
			path = envp[i];
			break ;
		}
	}
	path += 4;
	split_path = ft_split(path, ':');
	return (split_path);
}

static	void	exec_cmd(char *cmd, char **paths)
{
	char	*exec_path;
	pid_t	pid;
	int		fd[2];

	exec_path = check_access(cmd, paths);
	if (!exec_path)
		return ;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execve(exec_path, );
		exit();
	}
	wait_pid(pid);
	
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		//CHILD
		dup2(fd[1],STDOUT_FILENO);
		close(fd[0]);
		access(join, X_OK);
		execve();
		exit();
	}
	waitpid(pid);
	else
	{
		//PARENT
	}

	free_split(paths);
}
