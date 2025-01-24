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

#include "../include/pipex.h"

char	**get_path(char **env)
{
	char	*tmp;
	char	**path;

	path = (char **)malloc(sizeof(char *));
	if (!path)
		return (p_error("Alloc path eroor\n"), NULL);
	tmp = get_one_path (env);
	if (!tmp)
		return (free(path), NULL);
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
	return (path);
}

char	*get_one_path(char **env)
{
	while (*env)
	{
		if (!ft_strncmp("PATH", *env, 4))
			return (ft_strdup(*env));
		env++;
	}
	return (p_error("PATH not found\n"), NULL);
}
