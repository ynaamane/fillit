/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:58:31 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/15 18:53:32 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				ft_error(char *err, int n)
{
	ft_putstr(err);
	return (n);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		ft_error("usage: ./fillit target_file", 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (validate_file(fd) == true)
		ft_putstr("Valid!");
	else
		ft_putstr("Not valid!");
	close(fd);
	return (1);
}
