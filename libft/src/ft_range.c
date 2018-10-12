/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:45:45 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/06 20:46:25 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *mm;
	int i;

	i = 0;
	if (max <= min)
		return (0);
	mm = (int*)malloc(sizeof(*mm) * (max - min));
	if (!mm)
		return (NULL);
	while (min < max)
		mm[i++] = min++;
	return (mm);
}
