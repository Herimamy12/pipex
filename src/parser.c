/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:18:31 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/17 11:18:32 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_data	*new_data(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 5)
		return (p_error("Argument must be four\n"), NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (p_error("Alloc data error\n"), NULL);
	data->path = get_path(env);
	if (!data->path)
		return (free(data), NULL);
	data->cmd1 = new_cmd(argv[2], data->path);
	data->cmd2 = new_cmd(argv[3], data->path);
	data->file1 = new_file(argv[1], 'R');
	data->file2 = new_file(argv[4], 'W');
	if (!data->cmd1 || !data->cmd2 || data->file1 == -1 || data->file2 == -1)
		return (destroy_data(data), NULL);
	return (data);
}

int	new_file(char *path, char type)
{
	int		fd;

	if (type == 'R')
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (p_error("Can't open "), p_error(path), p_error("\n"), fd);
	return (fd);
}

t_cmd	*new_cmd(char *argv, char **path)
{
	t_cmd	*cmd;
	t_list	*lst;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (p_error("Alloc cmd error\n"), NULL);
	lst = get_list(argv, "");
	cmd->arg = get_arg(lst);
	cmd->cmd = get_cmd(cmd->arg[0], path);
	if (!cmd->cmd || !cmd->arg)
		return (destroy_cmd(cmd), ft_lstclear(&lst, free), NULL);
	return (ft_lstclear(&lst, free), cmd);
}

char	**get_arg(t_list *lst)
{
	int		len;
	char	**arg;

	len = ft_lstsize(lst);
	arg = (char **)malloc(sizeof(char *) * (len + 1));
	if (!arg)
		return (p_error("Alloc arg error\n"), NULL);
	len = 0;
	while (lst)
	{
		arg[len++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	arg[len] = NULL;
	return (arg);
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
