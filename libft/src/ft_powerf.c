/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:37:32 by opletsan          #+#    #+#             */
/*   Updated: 2018/09/30 17:37:36 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_powerf(float nb, int power)
{
	float	res;

	res = 1l;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		if (power & 1)
			res *= nb;
		nb *= nb;
		power >>= 1;
	}
	return (res);
}
