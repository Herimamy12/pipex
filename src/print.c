/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:41:35 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/24 23:41:37 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	p_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	p_splited(char **split)
{
	while (*split)
	{
		ft_printf("%s ", *split);
		split++;
	}
	ft_printf("\n");
}

void	p_cmd(char *title, t_cmd *cmd)
{
	ft_printf("%s->cmd :: %s || %s->arg :: ", title, cmd->cmd, title);
	p_splited(cmd->arg);
}

void	p_data(t_data *data)
{
	ft_printf("\n\n\n=======*** DATA ***=======\n");
	p_cmd("data->cmd1", data->cmd1);
	p_cmd("data->cmd2", data->cmd2);
	ft_printf("=======*** PIPX ***=======\n\n\n");
}
