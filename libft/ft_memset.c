/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:26:40 by qutrinh           #+#    #+#             */
/*   Updated: 2018/11/24 18:26:46 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    while (len > 0)
    {
        len--;
        ((unsigned char *)b)[len] = (unsigned char)c;
    }
    return (b);
}
