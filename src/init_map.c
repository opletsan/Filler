/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 21:23:46 by opletsan          #+#    #+#             */
/*   Updated: 2018/09/21 21:23:49 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	src_enemy(t_var *s)
{
	t_pos	m;

	m.y = s->en.y;
	while (s->map[m.y])
	{
		m.x = (s->en.x == -1) ? 0 : s->en.x + 1;
		s->en.x = -1;
		while (s->map[m.y][m.x])
		{
			if (s->map[m.y][m.x] == s->😡 || s->map[m.y][m.x] == s->😡 + 32)
			{
				s->hmap[m.y][m.x] = 10000000000.0;
				s->en.y = m.y;
				s->en.x = m.x;
				return (1);
			}
			m.x++;
		}
		m.y++;
	}
	return (0);
}

static inline void	heat_map(t_var *s, int f)
{
	t_pos			m;
	intmax_t		amt;
	static float	dis;

	amt = 0;
	while (src_enemy(s))
	{
		m.y = -1;
		while (s->map[++m.y])
		{
			m.x = -1;
			while (s->map[m.y][++m.x])
			{
				dis = ft_sqrtf(ft_power(s->en.x - m.x, 2) +
						ft_power(s->en.y - m.y, 2));
				if ((s->map[m.y][m.x] == '.' || s->map[m.y][m.x] == s->😎 ||
						s->map[m.y][m.x] == s->😎 + 32) &&
						(f || (!f && dis < s->hmap[m.y][m.x])))
					s->hmap[m.y][m.x] = dis;
			}
		}
		f -= f;
		amt++;
	}
	s->amt_en = (s->amt_en <= amt) ? amt : -1;
}

static inline int	next_line(t_var *s)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		++i;
		if (!*line || i > 2)
		{
			free(line);
			ft_dprintf(s->fd,
				"Error: nonvalid line in the beginning of the map !\n");
			return (0);
		}
		if (line[2] == ' ')
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (1);
}

int					get_map(t_var *s)
{
	char	*line;
	int		i;

	if (!next_line(s))
		return (0);
	i = -1;
	while (s->map[++i])
	{
		if (get_next_line(0, &line) < 0)
		{
			ft_dprintf(s->fd, "Error: no line in the map !\n");
			return (0);
		}
		if (!ft_strchr(line, ' '))
		{
			free(line);
			ft_dprintf(s->fd, "Error: empty line in the map !\n");
			return (0);
		}
		ft_strcpy(s->map[i], ft_strchr(line, ' ') + 1);
		free(line);
	}
	if (s->amt_en != -1)
		heat_map(s, 1);
	return (1);
}

int					create_map(t_var *s, char *line, char *tmp)
{
	static int	i = -1;
	t_pos		mps;

	if (get_next_line(0, &line) < 0)
	{
		ft_dprintf(s->fd, "Error: empty line in the beginning of the map !\n");
		return (0);
	}
	mps.y = (line[8]) ? ft_atoi(&line[8]) : 0;
	tmp = ft_strchr(&line[8], ' ');
	mps.x = (tmp) ? ft_atoi(tmp) : 0;
	free(line);
	if (mps.y <= 0 || mps.x <= 0 ||
			!(s->map = (char**)ft_memalloc(sizeof(char*) * (mps.y + 1))) ||
			!(s->hmap = (float**)ft_memalloc(sizeof(float*) * (mps.y + 1))))
	{
		ft_dprintf(s->fd, "Error: nonvalid size of the map !\n");
		return (0);
	}
	while (++i < mps.y)
	{
		s->map[i] = ft_strnew(mps.x);
		s->hmap[i] = (float*)malloc(sizeof(float) * mps.x);
	}
	return (1);
}
