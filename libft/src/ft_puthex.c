/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:55:20 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/23 16:55:33 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(long long int n)
{
	char			*s;
	long long int	len;
	long long int	x;

	x = n;
	len = 1;
	while (x /= 16)
		len++;
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	s[len] = '\0';
	while (len >= 0)
	{
		s[--len] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}
