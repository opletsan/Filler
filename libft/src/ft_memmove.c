/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:44:00 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 17:21:19 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*res;

	if (!dst && !src)
		return (NULL);
	res = (unsigned char*)dst;
	if (dst <= src)
		while (len > 0)
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			dst++;
			src++;
			len--;
		}
	else
		while (len > 0)
		{
			*(unsigned char*)(dst + len - 1) = *(unsigned char*)(src + len - 1);
			len--;
		}
	return (res);
}
