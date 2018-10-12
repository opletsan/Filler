/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:58:17 by opletsan          #+#    #+#             */
/*   Updated: 2017/11/15 19:09:30 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*buf;

	if (!lst)
		return ;
	while (lst)
	{
		buf = lst->next;
		free(lst->content);
		free(lst);
		lst = buf;
	}
	lst = NULL;
}
