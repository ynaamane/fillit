/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:15:59 by ynaamane          #+#    #+#             */
/*   Updated: 2019/03/25 16:20:44 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Adding backtracking to the solver
*/

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_etris		*tetri;

	if (list == NULL)
		return(1);
	y = 0;
	tetri = (t_etris *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->height + 1)
		{
			if (place(tetri, map, x , y))
			{
				if (solve_map(map, list->next))
					return(1);
				else
					set_piece(tetri, map, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return(0);
}

int		high_sqrt(int n)
{
	int		size;

	size = 2;
	while(size * size < n)
		size++;
	return(size);
}
