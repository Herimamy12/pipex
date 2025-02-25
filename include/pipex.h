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

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "../libft/include/libft.h"

typedef struct s_cmd
{
	char			*cmd;
	char			**arg;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_data
{
	int		hd;
	int		fds[2];
	int		file1;
	int		file2;
	t_cmd	*cmd;
	char	**path;
}			t_data;

//
// ------------------------DESTROY
//
void	destroy_cmd(t_cmd *cmd);
void	destroy_data(t_data *data);
void	destroy_splited(char **split, char **tmp);
void	cmd_clear(t_cmd **lst);

//
// ------------------------DEBUG FUNCTION && ERROR
//
void	p_error(char *str);
void	p_splited(char **split);
void	p_cmd(char *title, t_cmd *cmd);
void	p_data(t_data *data);
void	p_list(t_list *lst);

//
// ------------------------PARSER
//
t_data	*new_data(int argc, char **argv, char **env);
char	**get_more_path(char *tmp);
char	*get_one_path(char **env);
char	**get_path(char **env);
char	**add_suffix(char **path, char **tmp);
char	*get_cmd(char *argv, char **path);
t_cmd	*new_cmd(char *argv, char **path);
char	**get_arg(t_list *lst);
int		new_file(char *path, char type);
t_list	*get_list(char *argv, char *tmp);
int		parse_quote(char *argv, char **str, char set);
void	add_list(t_list **lst, char **str);
t_cmd	*get_all_cmd(int argc, char **argv, char **path);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*last_cmd(t_cmd *lst);

//
// ------------------------EXEC
//
int		exec_pipex(t_data *data, char **env);
int		exec_in_child(t_cmd *cmd, char **env, t_data *data);
int		set_stream(int *fds, int stream);

#endif
