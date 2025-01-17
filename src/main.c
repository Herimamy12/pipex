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
		return (p_error("Data not created\n"), 2);
	return (0);
}

// int	main(int argc, char **argv, char **env)
// {
// 	char	*arg[]={
// 		"-l",
// 		"-m",
// 		NULL
// 	};
// 	t_data	*data;

// 	// execve("/bin/ls", arg, env);
// 	data = new_data(argc, argv, env);
// 	if (!data)
// 		return (p_error("Data not created\n"), 2);
// 	return (0);
// }
