/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:09:06 by sebbaill          #+#    #+#             */
/*   Updated: 2018/12/13 16:44:58 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void    *ft_memset(void *b, int c, size_t len)
{
    while (len > 0)
    {
        len--;
        ((unsigned char *)b)[len] = (unsigned char)c;
    }
    return (b);
=======
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*temp;

	temp = s;
	i = 0;
	while (i < n)
		temp[i++] = c;
	return (s);
>>>>>>> 41189c25c31dbeb9a84ceeafea3d61c8409e678e
}
