/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:38:49 by opletsan          #+#    #+#             */
/*   Updated: 2018/09/21 22:38:53 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline float	check_cells(t_var *s, int sx, float dis, int amt)
{
	s->pc.y = s->fst.y;
	while (s->map[s->mp.y])
	{
		s->mp.x = s->mp0.x - sx;
		s->pc.x = s->fst.x;
		while (s->pic[s->pc.y][s->pc.x])
		{
			amt += ((s->map[s->mp.y][s->mp.x] == s->😎 + 32 ||
					s->map[s->mp.y][s->mp.x] == s->😎) &&
					s->pic[s->pc.y][s->pc.x] == '*');
			if (s->pic[s->pc.y][s->pc.x] == '*' && ((s->mp.y == s->mp0.y &&
					s->mp.x == s->mp0.x) || s->map[s->mp.y][s->mp.x] == '.'))
				dis += s->hmap[s->mp.y][s->mp.x];
			else if (amt > 1 || (s->pic[s->pc.y][s->pc.x] == '*' &&
					s->map[s->mp.y][s->mp.x] != '.'))
				return (-1.0);
			s->pc.x++;
			s->mp.x++;
		}
		if (++s->mp.y && ++s->pc.y >= s->pcs.y && amt == 1)
			return (dis);
		else if (s->pc.y >= s->pcs.y || amt > 1)
			break ;
	}
	return (-1.0);
}

static inline void	shift_on_map(t_var *s)
{
	t_pos	sh;
	float	ret;

	sh.x = 0;
	sh.y = 0;
	ret = 0.0;
	while (ret != 2.0)
	{
		s->mp.y = s->mp0.y - sh.y;
		if ((ret = check_cells(s, sh.x, 0.0, 0)) > 0.0 &&
				(ret < s->dis || s->dis == -1.0))
		{
			s->dis = ret;
			s->ret.x = s->mp0.x - sh.x - s->fst.x;
			s->ret.y = s->mp0.y - sh.y - s->fst.y;
		}
		if ((++sh.x >= s->pcs.x || (s->mp0.x - sh.x) < 0) && !(sh.x = 0) &&
				(++sh.y >= s->pcs.y || (s->mp0.y - sh.y) < 0))
			ret = 2.0;
	}
}

void				src_best_place(t_var *s)
{
	t_pos		m;

	m.y = -1;
	s->dis = -1.0;
	s->ret.x = 0;
	s->ret.y = 0;
	while (s->map[++m.y])
	{
		m.x = -1;
		while (s->map[m.y][++m.x])
		{
			if (s->map[m.y][m.x] == s->😎 || s->map[m.y][m.x] == s->😎 + 32)
			{
				s->mp0.x = m.x;
				s->mp0.y = m.y;
				shift_on_map(s);
				if (s->amt_en == -1 && s->dis != -1)
					return ;
			}
		}
	}
}
