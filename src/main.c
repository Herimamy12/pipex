/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:07:03 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/17 11:07:04 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = new_data(argc, argv, env);
	if (!data)
		return (p_error("Sorry!!! Data not created\n"), 2);
	if (exec_pipex(data, env) == -1)
		return (p_error("Can't execute\n"), destroy_data(data), 4);
	destroy_data (data);
	return (0);
}

int	exec_pipex(t_data *data, char **env)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		return(p_error("pipe() failed"), -1);
	pid = fork();
	if (pid == -1)
		return(p_error("fork() failed\n"), -1);
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		if (dup2(data->file1, 0) == -1)
			p_error("dup2() failed"), exit(-1);
		execve(data->cmd1->cmd, data->cmd1->arg, env);
		perror(data->cmd1->cmd);
		destroy_data (data);
		exit (4);
	}
	wait(NULL);
	close(fds[1]);
	dup2(fds[0], 0);
	close(fds[0]);
	if (dup2(data->file2, 1) == -1)
		return(p_error("dup2() failed"), -1);
	execve(data->cmd2->cmd, data->cmd2->arg, env);
	perror(data->cmd2->cmd);
	return (-1);
}
