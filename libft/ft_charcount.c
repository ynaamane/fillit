/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:02:26 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/22 18:24:51 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_charcount(char c, char *str)
{
	int		i;
	int		count;

	if (!str)
		return ('\0');
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
