/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:04:10 by opletsan          #+#    #+#             */
/*   Updated: 2018/10/06 23:04:13 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	first_star_line(t_var *s)
{
	int	x;
	int	y;
	int	f1;
	int	f2;

	s->fst.x = -1;
	s->fst.y = -1;
	y = -1;
	f2 = 0;
	while (s->pic[++y])
	{
		x = -1;
		f1 = 0;
		while (s->pic[y][++x])
		{
			if (s->pic[y][x] == '*' && (f1 = 1) && s->fst.y == -1)
				s->fst.y = y;
			if (s->pic[y][x] == '*' && (x < s->fst.x || s->fst.x == -1))
				s->fst.x = x;
		}
		if (!f1 && f2)
			return (y);
		f2 = (f1) ? 1 : 0;
	}
	return ((f2) ? s->pcs.y : 0);
}

static inline int	cut_piece(t_var *s)
{
	static int i;
	static int j;

	if (!(j = first_star_line(s)))
	{
		ft_dprintf(s->fd, "Error: no star in the piece !\n");
		return (0);
	}
	i = j;
	while (j < s->pcs.y)
	{
		free(s->pic[j]);
		s->pic[j] = NULL;
		j++;
	}
	s->pcs.y = i;
	return (1);
}

int					get_piece(t_var *s, char *line, int i)
{
	char	*tmp;

	if (get_next_line(0, &line) < 0)
	{
		ft_dprintf(s->fd, "Error: empty line in the beginning of piece !\n");
		return (0);
	}
	s->pcs.y = (line[6]) ? ft_atoi(&line[6]) : 0;
	tmp = ft_strchr(&line[6], ' ');
	s->pcs.x = (tmp) ? ft_atoi(tmp) : 0;
	free(line);
	if (s->pcs.y <= 0 || s->pcs.x <= 0 ||
			!(s->pic = (char**)ft_memalloc(sizeof(char*) * (s->pcs.y + 1))))
	{
		ft_dprintf(s->fd, "Error: nonvalid size of the piece !\n");
		return (0);
	}
	while (++i < s->pcs.y && get_next_line(0, &line) > 0)
		s->pic[i] = line;
	if (i != s->pcs.y)
	{
		ft_dprintf(s->fd, "Error: nonvalid line in the piece !\n");
		return (0);
	}
	return (cut_piece(s) ? 1 : 0);
}
