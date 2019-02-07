/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:12 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/07 17:57:57 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_bool	validate_count(char *tetri)
{
	int		line;
	int		col;
	int		i;

	line = 0;
	i = 0;
	while (tetri[i] != 0 && i < 20)
	{
		col = 0;
		while (tetri[i] != '\n' && tetri[i] != '\0')
		{
			col++;
			i++;
		}
		if (col != 4)
			return (false);
		i++;
		line++;
		if (line > 5 || line < 4 || (tetri[20] != '\n' && tetri[20] != '\0'))
				return (false);
		return (true);
	}
}
