/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:28:55 by sebbaill          #+#    #+#             */
/*   Updated: 2019/02/22 17:40:22 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int			get_save(char **save, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*save, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*save);
		*save = ft_strcpy(*save, tmp + 1);
		return (1);
	}
	return (0);
}

static int			get_line(char *buff, char **save, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buff, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*save, buff);
		ft_strdel(save);
		*save = ft_strdup(tmp + 1);
		return (1);
	}
	return (0);
}

static int				get_last_line(char **save, char **line)
{
	*line = *save;
	*save = NULL;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*save = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				head;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!save)
		save = ft_strnew(0);
	else if (get_save(&save, line))
		return (1);
	while ((head = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[head] = '\0';
		if (get_line(buff, &save, line))
			return (1);
		tmp = save;
		save = ft_strjoin(save, buff);
		ft_strdel(&tmp);
	}
	if (*save)
		return (get_last_line(&save, line));
	ft_strdel(&save);
	return ((head == -1) ? -1 : 0);
}
