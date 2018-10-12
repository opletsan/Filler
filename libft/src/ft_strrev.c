/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:25:50 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/16 17:37:46 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	l;
	char	tmp;

	i = 0;
	l = 0;
	while (str[i] != '\0')
		i++;
	while (l < --i)
	{
		tmp = str[l];
		str[l] = str[i];
		str[i] = tmp;
		l++;
	}
	return (str);
}
