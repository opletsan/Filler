/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:15:26 by opletsan          #+#    #+#             */
/*   Updated: 2018/09/18 19:15:28 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	get_players(t_var *s)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
	{
		ft_dprintf(s->fd, "Error: empty first line ️!\n");
		return (0);
	}
	if (line[10] != '1' && line[10] != '2')
	{
		ft_dprintf(s->fd, "Error: nonvalid number player !\n");
		free(line);
		return (0);
	}
	s->😎 = (line[10] == '1') ? 'O' : 'X';
	s->😡 = (s->😎 == 'O') ? 'X' : 'O';
	free(line);
	return (1);
}

static inline void	game_loop(t_var *s)
{
	while (1)
	{
		s->en.x = -1;
		s->en.y = 0;
		if (get_map(s) && get_piece(s, NULL, -1))
		{
			src_best_place(s);
			ft_free((void***)&s->pic);
			ft_printf("%d %d\n", s->ret.y, s->ret.x);
		}
		else
		{
			if (s->pic)
				ft_free((void***)&s->pic);
			if (s->map)
				ft_free((void***)&s->map);
			if (s->hmap)
				ft_free((void***)&s->hmap);
			return ;
		}
	}
}

int					main(void)
{
	t_var	s;

	remove("my.trace");
	ft_bzero(&s, sizeof(t_var));
	s.fd = open("my.trace", O_CREAT | O_RDWR | O_APPEND, 0666);
	if (get_players(&s) && create_map(&s, NULL, NULL))
		game_loop(&s);
	system("echo 'Leaks program:' >> my.trace");
	system("leaks -q opletsan.filler >> my.trace");
	ft_printf("%d %d\n", s.ret.y, s.ret.x);
	return (0);
}
