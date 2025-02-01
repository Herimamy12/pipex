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

char	*get_cmd_parse(char *argv, char *tmp, char **path);
int		count_quote(char *argv);

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
	// char	*parse;

	// parse = let_parse(path);
	if (type == 'R')
		fd = open(path, O_RDONLY);
	// else
	// 	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (p_error("Can't open "), p_error(path), p_error("\n"), fd);
	return (fd);
}

t_cmd	*new_cmd(char *argv, char **path)
{
	// char	*parse;
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (p_error("Alloc cmd error\n"), NULL);
	// parse = let_parse(argv);
	// cmd->cmd = get_cmd(argv, path);
	cmd->cmd = get_cmd_parse(argv, argv, path);
	cmd->arg = get_arg(argv);
	p_cmd("cmd", cmd);
	if (!cmd->cmd || !cmd->arg)
		return (destroy_cmd(cmd), NULL);
	return (cmd);
}

// char	*let_parse(char *str)
// {

// }

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

char	*get_cmd_parse(char *argv, char *tmp, char **path)
{
	int		nbr_quote;
	char	tmp_char;
	char	*cmd;

	nbr_quote = count_quote(argv);
	// if (!nbr_quote)
	// 	return (get_cmd(argv, path));
	if (nbr_quote % 2 != 0)
		return (p_error(argv), p_error(": quote not closed\n"), NULL);
	while (*argv && ft_iswhitespace(*argv))
		argv++;
	if (*argv == '\'')
		argv++;
	while (*argv && !ft_iswhitespace(*argv))
	{
		if (*argv == '\'')
			break ;
		tmp_char = *argv;
		cmd = ft_strjoin_get(cmd, &tmp_char);
		argv++;
	}
	return (cmd);
	(void)tmp;
	(void)path;
	(void)cmd;
}

int	count_quote(char *argv)
{
	int nbr;

	nbr = 0;
	while (*argv)
	{
		if (*argv == '\'')
			nbr++;
		argv++;
	}
	return (nbr);
}
