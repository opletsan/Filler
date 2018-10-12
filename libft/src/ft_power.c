/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:52:42 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/08 17:53:06 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int a;

	a = nb;
	if (power > 1)
	{
		while (power > 1)
		{
			nb *= a;
			power--;
		}
		return (nb);
	}
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	return (0);
}
