/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:25:03 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 21:22:31 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					f;

	res = 0;
	f = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		f = -1;
	if (*str == '+' || *str == '-')
		str++;
	str--;
	while (*(++str) != '\0')
		if (*str >= '0' && *str <= '9')
		{
			res = res * 10 + (*str - '0');
			if (res >= 9223372036854775807 && f == 1)
				return (-1);
			else if (res > 9223372036854775807 && f == -1)
				return (0);
		}
		else
			break ;
	return (res * f);
}
