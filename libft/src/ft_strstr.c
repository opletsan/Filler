/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:23:03 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/16 16:55:06 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!str && !to_find)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j + i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return ((char*)str + j);
			i++;
		}
		j++;
	}
	return (0);
}
