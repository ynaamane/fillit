/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:59:57 by ynaamane          #+#    #+#             */
/*   Updated: 2019/05/17 14:39:20 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			free_list(t_list **list)
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		free_tetris((t_etris**)&(*list)->content);
		free(*list);
		*list = next;
	}
}

void			free_tetris(t_etris **tetri)
{
	int y;

	y = 0;
	while (y < (*tetri)->height)
	{
		ft_strdel(&(*tetri)->pos[y]);
		y++;
	}
	free((*tetri)->pos);
	free(*tetri);
}

t_etris			*tetris_new(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->value = value;
	tetris->height = height;
	tetris->width = width;
	return (tetris);
}

t_point			*point_new(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
