/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:46:04 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 21:20:13 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		f;

	f = n;
	if (n == -2147483648)
		f = -214748364;
	if (f < 0)
	{
		ft_putchar_fd('-', fd);
		f = (-1) * f;
	}
	if (f > 9)
		ft_putnbr_fd(f / 10, fd);
	c = f % 10 + '0';
	ft_putchar_fd(c, fd);
	if (n == -2147483648)
		ft_putchar_fd('8', fd);
}