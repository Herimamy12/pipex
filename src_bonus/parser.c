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

#include "../include/pipex_bonus.h"

t_data	*new_data(int argc, char **argv, char **env)
{
	if (argc < 5)
		return (p_error("Argument must be at least four\n"), NULL);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		return (here_data(argc, argv, env));
	return (norm_data(argc, argv, env));
}

t_data	*norm_data(int argc, char **argv, char **env)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (p_error("Alloc data error\n"), NULL);
	data->hd = 0;
	data->path = get_path(env);
	if (!data->path)
		return (free(data), NULL);
	data->file1 = new_file(argv[1], 'R');
	data->file2 = new_file(argv[--argc], 'W');
	data->cmd = get_all_cmd(--argc, ++argv, data->path);
	if (!data->cmd || data->file1 == -1 || data->file2 == -1)
		return (destroy_data(data), NULL);
	return (data);
}

t_data	*here_data(int argc, char **argv, char **env)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (p_error("Alloc data error\n"), NULL);
	data->hd = 1;
	data->path = get_path(env);
	if (!data->path)
		return (free(data), NULL);
	data->file1 = 0;
	data->file2 = new_file(argv[--argc], 'A');
	here_doc(data->fds, argv[2]);
	argv++;
	argc--;
	data->cmd = get_all_cmd(--argc, ++argv, data->path);
	if (!data->cmd || data->file1 == -1 || data->file2 == -1)
		return (destroy_data(data), NULL);
	return (data);
}

void	here_doc(int *fds, char *lim)
{
	char	*buff;

	if (pipe(fds) == -1)
		return (p_error ("pipe() here_doc error\n"));
	buff = get_next_line(0);
	while (ft_strncmp(buff, lim, ft_strlen(buff) - 1))
	{
		ft_putstr_fd(buff, fds[1]);
		free(buff);
		buff = get_next_line(0);
	}
	free(buff);
	close(fds[1]);
}

int	new_file(char *path, char type)
{
	int		fd;

	fd = 0;
	if (type == 'R')
		fd = open(path, O_RDONLY);
	else if (type == 'W')
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (type == 'A')
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
		return (p_error("Can't open "), p_error(path), p_error("\n"), fd);
	return (fd);
}
