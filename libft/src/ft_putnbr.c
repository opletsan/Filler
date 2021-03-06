/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:19:50 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 21:19:59 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	c;
	int		f;

	f = n;
	if (n == -2147483648)
		f = -214748364;
	if (f < 0)
	{
		ft_putchar('-');
		f = (-1) * f;
	}
	if (f > 9)
		ft_putnbr(f / 10);
	c = f % 10 + '0';
	ft_putchar(c);
	if (n == -2147483648)
		ft_putchar('8');
}
