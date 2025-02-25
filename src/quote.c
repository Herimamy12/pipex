/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:54:07 by nherimam          #+#    #+#             */
/*   Updated: 2025/02/25 12:54:10 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_list	*get_list(char *argv, char *tmp)
{
	char	*str;
	t_list	*lst;

	str = NULL;
	lst = NULL;
	while (*argv)
	{
		if (ft_iswhitespace(*argv))
		{
			if (argv++ && str)
				add_list(&lst, &str);
		}
		else if (*argv == '\'' || *argv == '"')
			argv += parse_quote(argv, &str, *argv);
		else
		{
			tmp = ft_substr(argv, 0, 1);
			str = ft_strjoin_get(str, tmp);
			free (tmp);
			argv++;
		}
	}
	if (str)
		add_list(&lst, &str);
	return (lst);
}

void	add_list(t_list **lst, char **str)
{
	ft_lstadd_back(lst, ft_lstnew(ft_strdup(*str)));
	free(*str);
	*str = NULL;
}

int	parse_quote(char *argv, char **str, char set)
{
	int		len;
	char	*tmp;
	char	*index;

	if (set == '\'')
		index = ft_strchr(++argv, '\'');
	else
		index = ft_strchr(++argv, '"');
	if (!index)
	{
		p_error("WARNING: Verify quote not closed\n");
		*str = ft_strjoin_get(*str, "'");
		return (1);
	}
	len = index - argv;
	tmp = ft_substr(argv, 0, len);
	*str = ft_strjoin_get(*str, tmp);
	return (free(tmp), len + 2);
}
