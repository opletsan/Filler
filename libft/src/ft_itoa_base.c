/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:06:40 by opletsan          #+#    #+#             */
/*   Updated: 2018/06/29 15:40:42 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char			*s;
	long long int	x;
	int				len;
	int				f;

	len = 1;
	f = 0;
	len += (value < 0 && base == 10);
	f += (value < 0 && base == 10);
	x = value;
	while (value /= base)
		len++;
	if (x < 0)
		x *= -1;
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	while ((len - f) >= 0)
	{
		s[--len] = "0123456789ABCDEF"[x % base];
		x /= base;
	}
	if (f)
		s[len] = '-';
	return (s);
}
