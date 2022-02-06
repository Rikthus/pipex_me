#include "../includes/pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*path_join(char *s1, char *s2)
{
	char	*path;
	int		i;
	int		j;

	path = malloc(sizeof(*path) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!path)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		path[i] = s1[i];
		i++;
	}
	path[i] = '/';
	i++;
	while (s2[j])
	{
		path[i] = s2[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

char	*check_access(char *cmd, char **split_path)
{
	int		i;
	char	*full_path;

	i = 0;
	while (split_path[i])
	{
		full_path = path_join(split_path[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		i++;
	}
	return (NULL);
}

char	*pathfinder(char *cmd, char **envp)
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
	path = check_access(cmd, split_path);
	free_split(split_path);
	return (path);
}
