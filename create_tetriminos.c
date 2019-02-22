/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:51:27 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/22 23:57:46 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			free_tetriminos(t_list *tetrimino_list)
{
	t_list			*elem;
	t_list			*tmp;

	elem = tetrimino_list;
	while (elem)
	{
		if (elem->content)
		{
			free((t_point *)((t_tetrimino *)elem->content)->p);
			free((t_tetrimino *)elem->content);
		}
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}

static t_list	*empty_tetriminos(void)
{
	t_tetrimino		*new_tetri;
	t_list			*new;
	int				i;

	if(!(new_tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	if(!(new_tetri->p = (t_point *)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		new_tetri->p[i] = -1;
		new_tetri->p[i] = -1;
		new_tetri->c = '0';
	}
	new = ft_lstnew(new_tetri, sizeof(t_tetrimino *));
	return (new);
}

static t_tetrimino	*create_tetrimino(char *tetrimino)
{
	int				i;
	t_tetrimino		term;

	i = 0;
	while (tetrimino[i++])
	{
		
	}
}
