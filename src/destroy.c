/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:17 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/17 13:31:19 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	destroy_splited (data->path, data->path);
	destroy_cmd (data->cmd1);
	destroy_cmd (data->cmd2);
	if (data->file1 != -1)
		close (data->file1);
	if (data->file2 != -1)
		close (data->file2);
	free (data);
}

void	destroy_splited(char **split, char **tmp)
{
	if (!split)
		return ;
	while (*split)
	{
		free(*split);
		split++;
	}
	free (tmp);
}

void	destroy_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->lst)
		ft_lstclear(&cmd->lst, free);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->arg)
		destroy_splited(cmd->arg, cmd->arg);
	free (cmd);
}
