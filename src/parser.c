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



t_cmd	*get_all_cmd(int argc, char **argv, char **path);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*last_cmd(t_cmd *lst);



t_data	*new_data(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc < 5)
		return (p_error("Argument must be at least four\n"), NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (p_error("Alloc data error\n"), NULL);
	data->path = get_path(env);
	if (!data->path)
		return (free(data), NULL);
	data->file1 = new_file(argv[1], 'R');
	data->file2 = new_file(argv[--argc], 'W');
	data->cmd = get_all_cmd(argc, ++argv, data->path);
	if (!data->cmd || data->file1 == -1 || data->file2 == -1)
		return (destroy_data(data), NULL);
	return (data);
}

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
	cmd->next = NULL;
	return (ft_lstclear(&lst, free), cmd);
}

t_list	*get_list(char *argv, char *tmp)
{
	char	*str;
	t_list	*lst;

	str = NULL;
	lst = NULL;
	while (*argv)
	{
		if (ft_iswhitespace(*argv))
		{
			if (argv++ && str)
				add_list(&lst, &str);
		}
		else if (*argv == '\'' || *argv == '"')
			argv += parse_quote(argv, &str, *argv);
		else
		{
			tmp = ft_substr(argv, 0, 1);
			str = ft_strjoin_get(str, tmp);
			free (tmp);
			argv++;
		}
	}
	if (str)
		add_list(&lst, &str);
	return (lst);
}

void	add_list(t_list **lst, char **str)
{
	ft_lstadd_back(lst, ft_lstnew(ft_strdup(*str)));
	free(*str);
	*str = NULL;
}

int	parse_quote(char *argv, char **str, char set)
{
	int		len;
	char	*tmp;
	char	*index;

	if (set == '\'')
		index = ft_strchr(++argv, '\'');
	else
		index = ft_strchr(++argv, '"');
	if (!index)
	{
		p_error("WARNING: Verify quote not closed\n");
		*str = ft_strjoin_get(*str, "'");
		return (1);
	}
	len = index - argv;
	tmp = ft_substr(argv, 0, len);
	*str = ft_strjoin_get(*str, tmp);
	return (free(tmp), len + 2);
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
