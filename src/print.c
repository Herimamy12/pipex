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
		ft_printf("%s\n", *split);
		split++;
	}
}
