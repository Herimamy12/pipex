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
	t_cmd	*cmd;

	cmd = data->cmd;
	if (dup2(data->file1, 0) == -1)
		return (p_error("Dup input error\n"), -1);
	while (cmd)
	{
		if (cmd->next && (exec_in_child(cmd, env, data) == -1))
			return (-1);
		else if (!cmd->next)
		{
			if (dup2(data->file2, 1) == -1)
				return (p_error("Dup output error\n"), -1);
			execve(cmd->cmd, cmd->arg, env);
			perror(cmd->cmd);
		}
		cmd = cmd->next;
	}
	return (-1);
}

int	exec_in_child(t_cmd *cmd, char **env, t_data *data)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		return (p_error ("pipe() failed"), -1);
	pid = fork();
	if (pid == -1)
		return (p_error ("fork() failed\n"), -1);
	if (!pid)
	{
		if (set_stream(fds, 1))
			return (-1);
		execve(cmd->cmd, cmd->arg, env);
		perror(cmd->cmd);
		destroy_data (data);
		exit (4);
	}
	wait(NULL);
	if (set_stream(fds, 0))
		return (-1);
	return (0);
}

int	set_stream(int *fds, int stream)
{
	if (close(fds[!stream]) == -1)
		return (p_error("close() failed\n"), 1);
	if (dup2(fds[stream], stream) == -1)
		return (p_error("dup2() failed\n"), 1);
	if (close(fds[stream]) == -1)
		return (p_error("close() failed\n"), 1);
	return (0);
}
