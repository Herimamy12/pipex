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
	size_t	len;

	len = 8;
	if (ft_strlen(argv[1]) > len)
		len = ft_strlen(argv[1]);
	if (!ft_strncmp(argv[1], "here_doc", len))
		return (here_data(argc, argv, env));
	return (norm_data(argc, argv, env));
}

t_data	*norm_data(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc < 5)
		return (p_error("Argument must be at least four\n"), NULL);
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

	if (argc < 6)
		return (p_error("Argument must be at least five for here_doc\n"), NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (p_error("Alloc data error\n"), NULL);
	data->hd = 1;
	data->path = get_path(env);
	if (!data->path)
		return (free(data), NULL);
	data->file1 = -1;
	data->file2 = new_file(argv[--argc], 'A');
	here_doc(data->fds, argv[2]);
	argv++;
	argc--;
	data->cmd = get_all_cmd(--argc, ++argv, data->path);
	if (!data->cmd || data->file2 == -1)
		return (destroy_data(data), NULL);
	return (data);
}

void	here_doc(int *fds, char *lim)
{
	size_t	len;
	char	*buff;

	if (pipe(fds) == -1)
		return (p_error ("pipe() here_doc error\n"));
	len = ft_strlen(lim);
	buff = get_next_line(0);
	if (ft_strlen(buff) - 1 > len)
		len = ft_strlen(buff) - 1;
	while (ft_strncmp(buff, lim, len))
	{
		ft_putstr_fd(buff, fds[1]);
		free(buff);
		len = ft_strlen(lim);
		buff = get_next_line(0);
		if (ft_strlen(buff) - 1 > len)
			len = ft_strlen(buff) - 1;
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
