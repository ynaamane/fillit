/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:17:24 by ynaamane          #+#    #+#             */
/*   Updated: 2019/03/20 17:13:48 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.c"

/*
** Free an alocated map structure
*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel(void **)&(map->array[i]);
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map)
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
** Allocates a new map structure withe a given size
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

int		place(t_etris *tetris, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}
