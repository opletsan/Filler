/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:18:09 by opletsan          #+#    #+#             */
/*   Updated: 2018/10/04 21:18:12 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static inline void	start_game(char *line, char **p1, char **p2)
{
	int	i;

	i = 0;
	if (line[10] == '1')
	{
		ft_printf("{BBLC}%C", L'🔶');
		*p1 = ft_strdup(&line[15]);
		(*p1)[ft_strlen(*p1) - 1] = '\0';
		ft_printf("{BBLC}{TYEL}%s\n", &line[11]);
	}
	else
	{
		ft_printf("{BBLC}%C", L'🔷');
		*p2 = ft_strdup(&line[15]);
		(*p2)[ft_strlen(*p2) - 1] = '\0';
		ft_printf("{BBLC}{TCYN}%s\n", &line[11]);
	}
}

static inline void	game_loop(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		++i;
	while (line[++i])
	{
		if (line[i] == 'X')
			ft_printf("{BBLC}%C", L'🔷');
		else if (line[i] == 'x')
			ft_printf("{BBLC}%C", L'🔹');
		else if (line[i] == 'O')
			ft_printf("{BBLC}%C", L'🔶');
		else if (line[i] == 'o')
			ft_printf("{BBLC}%C", L'🔸');
		else if (line[i] == '.')
			ft_printf("{BBLC}%C", L'🔘');
		else
			ft_printf("{BBLC}%C", L'⭕');
	}
	ft_printf("\n");
}

static inline int	finish_game(char *line, char *p1, char *p2)
{
	static int	end = 0;
	static int	sp1 = 0;
	static int	sp2 = 0;

	if (!end)
		ft_printf("\n\033[1mScore:\033[0m\n");
	if (line[3] == 'X')
	{
		ft_printf("{BBLC}%C", L'🔷');
		sp2 = ft_atoi(&line[9]);
		ft_printf("{BBLC}{TCYN} %s\n", &line[8]);
	}
	else if (line[3] == 'O')
	{
		ft_printf("{BBLC}%C", L'🔶');
		sp1 = ft_atoi(&line[9]);
		ft_printf("{BBLC}{TYEL} %s\n", &line[8]);
	}
	if (end && sp1 == sp2)
		ft_printf("\n\033[1m🏆 Draw 🏆\033[0m\n");
	else if (end && sp1 > sp2)
		ft_printf("\n\033[1m🏆 %s winner 🏆\033[0m\n", p1);
	else if (end && sp2 > sp1)
		ft_printf("\n\033[1m🏆 %s winner 🏆\033[0m\n", p2);
	return ((end++) ? 1 : 0);
}

int					main(void)
{
	char	*line;
	char	*p1;
	char	*p2;

	setlocale(LC_ALL, "");
	system("clear");
	system("tput civis");
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
			start_game(line, &p1, &p2);
		else if (!ft_strncmp("Plateau", line, 7))
			system("tput cup 3");
		else if (ft_isdigit(line[0]))
			game_loop(line);
		else if (line[0] == '=')
			if (finish_game(line, p1, p2))
				break ;
		ft_strdel(&line);
	}
	free(line);
	system("tput cnorm");
	system("echo 'Leaks visualization:' >> my.trace");
	system("leaks -q visualize >> my.trace");
	return (0);
}
