/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:17:24 by ynaamane          #+#    #+#             */
/*   Updated: 2019/03/28 11:20:33 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Free an alocated map structure
*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*
** Prints aleady allowed map to the standar outpout
*/

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while(i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** Allocates a new map structure with a given size
*/

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while(j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return(map);
}

/*
** This function allow you to place a tetriminos with a specified adress.
** Also checking of the placement is possible.
*/

int		place(t_etris *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return(0);
			j++;
		}
		i++;
	}
	set_piece(tetri, map, point_new(x, y), tetri->value);
	return(1);
}

/*
** Sets a tetrimino on a map at a position with the specified character.
** To place, call with c=tetri->value. To remove, call with c='.'.
*/

void	set_piece(t_etris *tetri, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while(i < tetri-> width)
	{
		j = 0;
		while(j < tetri->height)
		{
			if(tetri->pos[j][i] == '#')
				map->array[point->y +i][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdell((void **)&point);
}
