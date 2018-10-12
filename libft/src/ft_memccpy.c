/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:21:15 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 21:19:10 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
																	size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)dst = *(const unsigned char*)src;
		if (*(unsigned char*)dst == (unsigned char)c)
		{
			return (++dst);
			break ;
		}
		dst++;
		src++;
		n--;
	}
	return (0);
}
