/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:22:16 by nherimam          #+#    #+#             */
/*   Updated: 2025/02/24 09:22:18 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_cmd	*get_all_cmd(int argc, char **argv, char **path)
{
	int		index;
	t_cmd	*cmd;

	index = 1;
	cmd = NULL;
	while (index < argc)
	{
		cmd_add_back(&cmd, new_cmd(argv[index], path));
		index++;
	}
	return (cmd);
}

void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	if (new != NULL && lst[0] != NULL)
		last_cmd(lst[0])->next = new;
	else if (lst[0] == NULL)
		lst[0] = new;
}

t_cmd	*last_cmd(t_cmd *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

char	*get_cmd(char *argv, char **path)
{
	char	*cmd;

	while (*path)
	{
		cmd = ft_strjoin (*path, argv);
		if (!access(cmd, X_OK))
			return (cmd);
		free (cmd);
		path++;
	}
	cmd = ft_strdup(argv);
	return (cmd);
}
