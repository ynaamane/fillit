/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:09:02 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 01:44:40 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_matrix(t_matrix matrix)
{
	int		row;
	int		col;
	int		i;

	row = 0;
	while (row < matrix.rows_nb)
	{
		col = 0;
		while (col < matrix.cols_nb)
		{
			if (matrix.m[row][col] == 1)
				printf(" \033[32m%d\033[0m ", matrix.m[row][col]);
			else if (matrix.m[row][col] == 0)
				printf(" \033[31m%d\033[0m ", matrix.m[row][col]);
			else
				printf(" %d ", matrix.m[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}
