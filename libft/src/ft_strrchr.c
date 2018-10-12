/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:28:00 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 21:21:14 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*entr;

	entr = s;
	while (*s != '\0')
		s++;
	while (s != entr)
	{
		if (*s == (char)c)
		{
			return ((char*)s);
			break ;
		}
		s--;
	}
	if (s == entr && *s == (char)c)
		return ((char*)s);
	return (0);
}
