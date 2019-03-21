/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:41:06 by qutrinh           #+#    #+#             */
/*   Updated: 2018/12/06 18:46:24 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	r;

	i = 0;
	j = ft_strlen(dst);
	l = ft_strlen(src);
	if (size < j + 1)
		return (l + size);
	r = l + j;
	if (size > j + 1)
	{
		k = size - j - 1;
		while (k > 0)
		{
			dst[j++] = src[i++];
			k--;
		}
		dst[j] = '\0';
	}
	return (r);
}
