/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:58:31 by ynaamane          #+#    #+#             */
/*   Updated: 2019/04/30 15:51:42 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

// int				print_error(char *err, int n)
// {
// 	ft_putstr(err);
// 	ft_putstr("\n");
// 	return (n);
// }

int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
