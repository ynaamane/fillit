/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:20:12 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/15 18:12:45 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef enum	e_bool
{
	true,
	false
}				t_bool;

typedef struct	s_point
{
	int			x;
	int			y;
	char		c;
}				t_point;

typedef struct	s_tetrimino
{
	t_point		*p;
	char		c;
}				t_tetrimino;

static int			ft_error(char *err, int n);
char				*get_pattern(int index);
static t_bool		validate_count(char *tetri);
t_bool				validate_file(int fd);

#endif
