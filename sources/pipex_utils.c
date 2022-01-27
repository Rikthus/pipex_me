/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:33:14 by maxperei          #+#    #+#             */
/*   Updated: 2022/01/27 15:56:26 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
