/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:58:59 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/04 17:29:14 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*isrc;

	len = 0;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	if (!(isrc = (char*)malloc(sizeof(*isrc) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		isrc[i] = src[i];
		i++;
	}
	isrc[i] = '\0';
	return (isrc);
}
