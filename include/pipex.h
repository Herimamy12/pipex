/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:07:14 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/17 11:07:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**arg;
}			t_cmd;

typedef struct s_data
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	*file1;
	char	*file2;
}			t_data;

//
// ------------------------DESTROY
//
void	destroy_cmd(t_cmd *cmd);

//
// ------------------------DEBUG FUNCTION && ERROR
//
void	p_error(char *str);

//
// ------------------------PARSER
//
t_data	*new_data(int argc, char **argv, char **env);

#endif
