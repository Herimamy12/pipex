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

int main(int argc, char **argv, char **env)
{
    write(1, argv[0], 5);
    write(1, "\n", 1);
    debug();
    return (0);
    (void)argc;
    (void)env;
}
