/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:41:31 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 22:13:05 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		f;

	f = n;
	s = ft_strnew(ft_numlen(n));
	if (!s)
		return (NULL);
	*s = '0';
	if (n == 0 || n == -0 || n == +0)
		return (s);
	if (n == -2147483648)
	{
		*(s++) = '8';
		n = 214748364;
	}
	n = ft_abs(n);
	while (n % 10 != 0 || n / 10 != 0)
	{
		*(s++) = n % 10 + '0';
		n /= 10;
	}
	if (f < 0)
		*(s++) = '-';
	return (ft_strrev(s - ft_numlen(f)));
}
