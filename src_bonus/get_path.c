/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:44:41 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/24 23:44:43 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**get_path(char **env)
{
	char	*tmp;
	char	**path;

	tmp = get_one_path (env);
	if (!tmp)
		return (NULL);
	path = get_more_path (tmp);
	if (!path)
		return (free(path), NULL);
	return (path);
}

char	**get_more_path(char *tmp)
{
	char	*one;
	char	**path;

	one = tmp + 5;
	path = ft_split(one, ':');
	if (!path)
		return (p_error("Splited PATH error\n"), NULL);
	free (tmp);
	path = add_suffix(path, path);
	return (path);
}

char	**add_suffix(char **path, char **tmp)
{
	while (*path)
	{
		*path = ft_strjoin_get(*path, "/");
		path++;
	}
	return (tmp);
}

char	*get_one_path(char **env)
{
	while (env && *env)
	{
		if (!ft_strncmp("PATH", *env, 4))
			return (ft_strdup(*env));
		env++;
	}
	return (p_error("PATH not found\n"), NULL);
}
