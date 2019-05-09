/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:06:05 by tdupont           #+#    #+#             */
/*   Updated: 2019/05/09 16:12:05 by ynaamane         ###   ########.fr       */
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

typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;

t_list			*read_tetri(int fd);
void			print_map(t_map *map);
void			free_map(t_map *map);
t_map			*map_new(int size);
int				place(t_etris *tetri, t_map *map, int x, int y);
void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c);
t_map			*solve(t_list *list);
t_point			*point_new(int x, int y);
t_etris			*tetris_new(char **pos, int width, int height, char c);
void			free_tetris(t_etris **tetri);
void			free_list(t_list **list);
void			ft_lstrev(t_list **alst);
size_t			ft_lstcount(t_list *lst);

#endif
