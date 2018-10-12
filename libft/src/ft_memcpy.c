/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:58:54 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 17:21:28 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*res;

	if (!dst && !src)
		return (NULL);
	res = (unsigned char*)dst;
	while (n > 0)
	{
		*(unsigned char*)dst = *(const unsigned char*)src;
		dst++;
		src++;
		n--;
	}
	return (res);
}
