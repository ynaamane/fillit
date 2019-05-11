/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:25:21 by ynaamane          #+#    #+#             */
/*   Updated: 2019/05/10 19:47:06 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

/*
** Backtracking implementation of the solver.
*/

int		solve_map(t_map **map, t_list **list)
{
	int			x;
	int			y;
	t_etris		*tetri;

	ft_putendl("ENTER SOLVE_MAP");
	if (list == NULL)
	{
		ft_putendl("if (list == NULL) return 1");
		return (1);
	}
	y = 0;
	ft_putendl("BEFORE TETRI=...");
	if ((*list)->content)							// <- Condition ajouter pour le debbug ne'empeche pas le seg
		tetri = (t_etris *)((*list)->content);				// <- Cause pricipal du seg
	ft_putendl("AFTER TETRI=...");
	while (y < (*map)->size - tetri->height + 1)
	{
		ft_putendl("SOLVE_MAP 1st WHILE");
		x = 0;
		while (x < (*map)->size - tetri->width + 1)
		{
			ft_putendl("SOLVE_MAP 2nd WHILE");
			if (place(tetri, *map, x, y))
			{
				ft_putendl("IF PLACE TETRI");
				if (solve_map(map, &(*list)->next))		// <- Cause potentiel (si premiere cause commenter)
				{
					ft_putendl("if (solve_map(map, &(*list)->next)) return (1)");
					return (1);
				}
				else
					set_piece(tetri, map, point_new(x, y), '.');
			}
			x++;
			ft_putendl("X++");
		}
		y++;
		ft_putendl("Y++");
	}
	return (0);
}

/*
** Gets the rounded up sqrt of a number. Equivalent to ceil(sqrt(n)).
*/

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Tries to solve maps starting from the smallest possible size.
*/

t_map	*solve(t_list **list)
{
	t_map	*map;
	int		size;

	ft_putendl("ENTER SOLVE");
	size = high_sqrt(ft_lstcount(*list) * 4);
	map = map_new(size);
	while (!solve_map(&map, list))
	{
		ft_putendl("ENTER IN WHILE");
		size++;
		free_map(&map);
		map = map_new(size);
	}
	ft_putendl("END SOLVE");
	return (map);
}
