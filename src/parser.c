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
	int	fd;

	if (type == 'R')
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 777);
	if (fd == -1)
		return (p_error("Can't open "), p_error(path), p_error("\n"), fd);
	return (fd);
}

t_cmd	*new_cmd(char *argv, char **path)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (p_error("Alloc cmd error\n"), NULL);
	cmd->cmd = get_cmd(argv, path);
	cmd->arg = get_arg(argv);
	if (!cmd->cmd || !cmd->arg)
		return (destroy_cmd(cmd), NULL);
	return (cmd);
}

char	**get_arg(char *argv)
{
	char	**arg;

	arg = ft_split(argv, ' ');
	if (!arg)
		return (p_error("Splited arg error\n"), NULL);
	return (arg);
}

char	*get_cmd(char *argv, char **path)
{
	char	*cmd;
	char	**all;

	all = ft_split(argv, ' ');
	if (!all)
		return (p_error("Splited cmd error\n"), NULL);
	while (*path)
	{
		cmd = ft_strjoin (*path, all[0]);
		if (!access(cmd, X_OK))
			return (destroy_splited(all, all), cmd);
		free (cmd);
		path++;
	}
	cmd = ft_strjoin (all[0], "");
	return (destroy_splited(all, all), cmd);
}
