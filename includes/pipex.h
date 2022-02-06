/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sap <sap@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:19:43 by maxperei          #+#    #+#             */
/*   Updated: 2022/02/02 13:51:08 by sap              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

# include "../libft/libft.h"

typedef struct s_data
{
	int		nb_cmds;
	char	**args;
	char	**envp;
	char	**base_paths;
	char	**full_cmd;
}	t_data ;

//////   PIPEX   //////

void	exec_cmd(int cmd_index, char **argv, char **envp);

//////   PROCESSES   //////

void	first_process(int cmd_index, int *pipe_fd, char **argv, char **envp);
void	last_process(int cmd_index, int *pipe_fd, char **argv, char **envp);
void	inter_process(int cmd_index, int *pipe_fd, char **argv, char **envp);

//////   UTILS   //////
void	free_split(char **split);
char	*path_join(char *s1, char *s2);
char	*check_access(char *cmd, char **split_path);
char	*pathfinder(char *cmd, char **envp);

#endif
