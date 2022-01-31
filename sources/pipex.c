/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:28:04 by maxperei          #+#    #+#             */
/*   Updated: 2022/01/31 16:43:04 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static char *check_access(char *cmd, char **env_path) // TO CHECK + JUSTE ENVOYER LA CMD SANS ARG
{
	int		i;
	int		valid_exec;
	char	*full_path;

	i = -1;
	valid_exec = -1;
	while (valid_exec == -1)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
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

static char **find_paths(char **envp) // TO CHECK
{
	char	*path;
	char	**split_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
		else
		{
			path = envp[i];
			break;
		}
	}
	path += 5;
	split_path = ft_split(path, ':');
	return (split_path);
}

static	void	child_process(int fd, char *cmd, char **envp, char **paths)
{

}

static	void	pipex(int *file, char **argv, char **envp, char **paths)
{
	char	**split_cmd;
	pid_t	pid;

	pid = fork();
	if (pid = -1)
		return ;
	if (pid == 0)
		child_process();
	else
	{

	}
	perror("Parent execution error");
	exit();
}

int	main(int argc, char **argv, char **envp)
{
	int		file[2];
	char	**paths;

	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[4], O_CREAT | O_RDWR, 0777);
	if (file[0] < 0 || file[1] < 0 || ft_strncmp(argv[1], "infile", 7) != 0)
		return (-1);
	paths = find_paths(envp);
	pipex(file, argv, envp, paths);
	// WHAT TO DO IF NOT ENOUGH ARGS ?
	free_split(paths);
	return (0);
}
