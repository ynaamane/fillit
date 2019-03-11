/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:58:31 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 03:49:30 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				print_error(char *err, int n)
{
	ft_putstr(err);
	return (n);
}

/*
**	Minimum starting board size
*/

static int		min_square(t_list *tetriminos)
{
	int			min_size;
	int			cell_nb;

	cell_nb = get_tetriminos_nb(tetriminos) * 4;
	min_size = 2;
	while (min_size * min_size < cell_nb)
		min_size++;
	return (min_size);
}

int				main(int ac, char **av)
{
	int			start_size;
	t_list		*tetriminos;
	t_matrix	*matrix;
	int			hole_nb;

	if (ac != 2)
		return (print_error("usage: ./fillit target_file", 0));
	if (!(tetriminos = get_tetriminos(av)))
		return (print_error("error", 0));
	print_tetriminos(tetriminos);
	start_size = min_square(tetriminos);
	printf("Board size is : %d\n", start_size);
	hole_nb = get_hole_nb(tetriminos, start_size);
	printf("Hole number is : %d\n", hole_nb);
	matrix = create_matrix(tetriminos, start_size, hole_nb);
	fill_matrix(matrix, tetriminos, hole_nb);
	print_matrix(*matrix);

	return (0);
}
