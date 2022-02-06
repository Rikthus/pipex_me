#include "../includes/pipex.h"

void	exec_cmd(int cmd_index, char **argv, char **envp)
{
	char	**split_cmd;
	char	*path;
	int		i;

	split_cmd = ft_split(argv[cmd_index], ' ');
	if (ft_strchr(split_cmd[0], 47))
	{
		if (access(split_cmd[0], X_OK) == 0)
			execve(split_cmd[0], split_cmd, envp);
	}
	else
	{
		path = pathfinder(split_cmd[0], envp);
		execve(path, split_cmd, envp);
		free(path);
	}
	free_split(split_cmd);
	perror("command exec failed");
	exit(1);
}

void	pipeline(int cmd_index, int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		return ;
	while (cmd_index < argc - 1)
	{
		pid = fork();
		if (pid == -1)
			return ;
		if (pid == 0)
		{
			if (cmd_index == 2)
				first_process(cmd_index, pipe_fd, argv, envp);
			else if (cmd_index == argc - 2)
				last_process(cmd_index, pipe_fd, argv, envp);
			else
				inter_process(cmd_index, pipe_fd, argv, envp);
			return ;
		}
		waitpid(pid)
		cmd_index++;
	}
	while (wait(NULL) != -1);
}

// static	void	pipeline(char **argv, char **envp)
// {
// 	int		pipe_fd[2];
// 	int		outfile;
// 	int		status;
// 	pid_t	pid;  //*pid

// 	if (pipe(pipe_fd) == -1)
// 		return ;
// 	pid = fork();
// 	if (pid == -1)
// 		return ;
// 	if (pid == 0)
// 		child_process(2, pipe_fd, argv, envp);
// 	else
// 	{
// 		waitpid(pid, &status, 0);
// 		outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
// 		if (outfile < 3)
// 			return ;
// 		if (dup2(outfile, STDOUT_FILENO) == -1)
// 			return ;
// 		close(pipe_fd[0]);
// 		close(outfile);
// 		exec_cmd(3, argv, envp);
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	int	cmd_index;
	if (argc < 5 || ft_strncmp(argv[1], "infile", 7) != 0)
		return(1);
	cmd_index = 2;
	pipeline(cmd_index, argc, argv, envp);
}
