/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:42:54 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/06 22:55:21 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *app, size_t dstsize)
{
	size_t	dl;
	size_t	al;
	size_t	i;

	dl = ft_strlen(dst);
	al = ft_strlen(app);
	if (dstsize < dl)
		return (al + dstsize);
	i = dl;
	while ((i < dstsize - 1) && *app != '\0')
	{
		dst[i] = *app;
		i++;
		app++;
	}
	dst[i] = '\0';
	return (dl + al);
}
