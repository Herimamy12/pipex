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
# include <stdlib.h>
# include <unistd.h>

# include "../libft/include/libft.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**arg;
}			t_cmd;

typedef struct s_data
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**path;
	char	*file1;
	char	*file2;
}			t_data;

//
// ------------------------DESTROY
//
void	destroy_cmd(t_cmd *cmd);
void	destroy_data(t_data *data);
void	destroy_splited(char **split);

//
// ------------------------DEBUG FUNCTION && ERROR
//
void	p_error(char *str);
void	p_splited(char **split);

//
// ------------------------PARSER
//
t_data	*new_data(int argc, char **argv, char **env);
char	**get_more_path(char *tmp);
char	*get_one_path(char **env);
char	**get_path(char **env);

#endif
