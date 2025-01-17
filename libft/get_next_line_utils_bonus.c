/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:25:07 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/21 10:30:54 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_get(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr_get(char *stash, int c)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_get(stash);
	while (i < len)
	{
		tmp = (char *)&stash[i];
		if (stash[i] == (char)c)
			return (tmp);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&stash[i]);
	return (0);
}

char	*ft_strjoin_get(char *stash, char *buff)
{
	size_t	i;
	char	*str;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen_get(stash);
	ls2 = ft_strlen_get(buff);
	str = ft_calloc_get(sizeof(char), (ls2 + ls1 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ls1)
	{
		str[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < ls2)
	{
		str[i + ls1] = buff[i];
		i++;
	}
	str[i + ls1] = '\0';
	free(stash);
	return (str);
}

char	*ft_createstash(int fd, char *stash)
{
	int		nbytes;
	char	*buff;

	buff = ft_calloc_get(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr_get(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[nbytes] = '\0';
		stash = ft_strjoin_get(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_createline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i] || stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc_get(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
