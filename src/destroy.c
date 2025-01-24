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
	destroy_splited (data->path);
	free (data);
}

void	destroy_splited(char **split)
{
	if (!split)
		return ;
	while (*split)
	{
		free(*split);
		split++;
	}
	// free (split);
}

// void	destroy_cmd(t_cmd *cmd)
// {
// 	if (!cmd)
// 		return ;
// 	if (cmd->cmd)
// 		free(cmd->cmd);
// 	if (cmd->arg)
// 		destroy_arg(cmd->arg);
// 	free (cmd);
// }
