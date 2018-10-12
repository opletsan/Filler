/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:49:18 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/06 20:37:57 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*ad;

	if (!s1 || !s2)
		return (NULL);
	res = (char*)malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	ad = res;
	while (*s1 != '\0')
	{
		*res = *s1;
		s1++;
		res++;
	}
	while (*s2 != '\0')
	{
		*res = *s2;
		s2++;
		res++;
	}
	*res = '\0';
	return (ad);
}
