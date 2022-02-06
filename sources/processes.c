#include "../includes/pipex.h"

void	first_process(int cmd_index, int *pipe_fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 3)
		exit(1);
	if (dup2(infile, STDIN_FILENO) == -1)
		exit(2);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		exit(3);
	close(pipe_fd[0]);
	close(infile);
	exec_cmd(cmd_index, argv, envp);
}

void	last_process(int cmd_index, int *pipe_fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 3)
		exit(4);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit(5);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit(6);
	close(pipe_fd[1]);
	close(outfile);
	exec_cmd(cmd_index, argv, envp);
}

void	inter_process(int cmd_index, int *pipe_fd, char **argv, char **envp)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit(7);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		exit(8);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec_cmd(cmd_index, argv, envp);
}
