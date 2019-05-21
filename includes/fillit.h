/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:18:19 by ynaamane          #+#    #+#             */
/*   Updated: 2019/05/21 17:34:47 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
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
}				t_board;

typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;

t_list			*read_tetri(int fd, int pieces);
void			print_map(t_map *map);
void			free_map(t_map **map);
int				solve_map(t_map **map, t_list **list);
int				high_sqrt(int n);
void			min_max(char *str, t_point *min, t_point *max);
void			free_tetris(t_etris **tetri);
t_etris			*tetris_new(char **pos, int width, int height, char value);
void			free_list(t_list **list);
void			set_piece(t_etris *tetri, t_map **map, t_point *point, char c);
t_map			*solve(t_list *ist);
t_point			*point_new(int x, int y);
t_etris			*tetris_new(char **pos, int width, int height, char c);
void			free_tetris(t_etris **tetri);
void			free_list(t_list **list);
void			ft_lstrev(t_list **alst);
size_t			ft_lstcount(t_list *lst);
int				place(t_etris *tetris, t_map *map, int x, int y);
t_map			*map_new(int size);

#endif
