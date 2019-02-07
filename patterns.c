/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:21:02 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/07 14:23:06 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		*get_pattern(int index)
{
	if (index < 0 || index > 18)
		return (NULL);
	if (index == 0)
		return (ft_strdup("##..##\0"));
	if (index == 1)
		return (ft_strdup("#...#...#...#\0"));
	if (index == 2)
		return (ft_strdup("####\0"));
	if (index == 3)
		return (ft_strdup("#...#...##\0"));
	if (index == 4)
		return (ft_strdup("###.#\0"));
	if (index == 5)
		return (ft_strdup("##...#...#\0"));
	if (index == 6)
		return (ft_strdup("#.###\0"));
	if (index == 7)
		return (ft_strdup("#...#..##\0"));
	if (index == 8)
		return (ft_strdup("#...###\0"));
	if (index == 9)
		return (ft_strdup("##..#...#\0"));
	return (get_pattern_part2(index));
}

static char	*get_pattern_part2(int index)
{
	if (index == 10)
		return (ft_strdup("###...#\0"));
	if (index == 11)
		return (ft_strdup("#..###\0"));
	if (index == 12)
		return (ft_strdup("#..##...#\0"));
	if (index == 13)
		return (ft_strdup("#...##..#\0"));
	if (index == 14)
		return (ft_strdup("###..#\0"));
	if (index == 15)
		return (ft_strdup("##...##\0"));
	if (index == 16)
		return (ft_strdup("#..##..#\0"));
	if (index == 17)
		return (ft_strdup("##.##\0"));
	if (index == 18)
		return (ft_strdup("#...##...#\0"));
	return (NULL);
}


