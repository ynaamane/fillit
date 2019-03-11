/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:20:12 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 02:25:37 by qutrinh          ###   ########.fr       */
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

typedef struct	s_board
{
	int			size;
	t_point		*p;
}					t_board;

typedef struct	s_matrix
{
	int			board_size;
	int			tetri_nb;
	int			cols_nb;
	int			rows_nb;
	int			**m;

}				t_matrix;

int				print_error(char *err, int n);
char			*get_pattern(int index);
t_bool			validate_file(int fd);
t_point			new_point(int a, int b);
t_list			*get_tetriminos(char **av);
t_bool			read_tetriminos(t_list *tetriminos, char *tetri_str, char c);
t_point			set_point(int a, int b);
void			print_board(t_board board);
t_bool			cmp_board(t_board board1, t_board board2);
t_board			dup_board(t_board board);
t_board			create_new_board(int size);
int				get_hole_nb(t_list *tetriminos, int board_size);
t_point			*find_point(int x, int y, t_board board);
t_bool			can_be_placed(t_tetrimino *t, t_point p, int board_size);
t_board			put_tetrimino(t_point p, t_tetrimino t, t_board board);
int				get_tetriminos_nb(t_list *tetriminos);
int				get_positions_nb(t_tetrimino *t, int board_size);
t_matrix		*create_matrix(t_list *tetriminos, int bsize, int hole_nb);

/*
** TO BE DELETED
*/
void			print_tetrimino(t_tetrimino tetrimino);
void			print_tetriminos(t_list *tetriminos);
void			print_matrix(t_matrix matrix);

#endif
