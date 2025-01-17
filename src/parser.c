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
	// t_cmd	*cmd1;
	// t_cmd	*cmd2;

	if (argc != 5)
		return (p_error("Argument must be four\n"), NULL);
	// cmd1 = new_cmd(argv[2], env);
	// cmd2 = new_cmd(argv[3], env);
	return (NULL);
	(void)argc;
	(void)argv;
	(void)env;
}

// t_cmd	*new_cmd(char *argv, char **env)
// {
// 	t_cmd	*cmd;

// 	cmd = (t_cmd *)malloc(sizeof(t_cmd));
// 	if (!cmd)
// 		return (p_error("Alloc error cmd\n"), NULL);
// 	cmd->cmd = get_cmd(argv, env);
// 	cmd->arg = get_arg(argv);
// 	if (!cmd->cmd || !cmd->arg)
// 		return (detrsoy_cmd(cmd), NULL);
// 	return (cmd);
// }

// char	**get_arg(char *argv)
// {
// 	char	**arg;

// 	arg = 
// }

// char	*get_cmd(char *argv, char **env)
// {
// 	char	*cmd;
// }

void	p_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}
