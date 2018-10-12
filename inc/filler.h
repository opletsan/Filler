/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:25:41 by opletsan          #+#    #+#             */
/*   Updated: 2018/09/17 17:26:43 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_var
{
	unsigned char	😎;
	unsigned char	😡;
	int				fd;
	intmax_t		amt_en;
	float			dis;
	char			**map;
	char			**pic;
	float			**hmap;
	t_pos			fst;
	t_pos			mp;
	t_pos			pc;
	t_pos			pcs;
	t_pos			mp0;
	t_pos			en;
	t_pos			ret;
}					t_var;

void				src_best_place(t_var *s);
int					get_piece(t_var *s, char *line, int i);
int					get_map(t_var *s);
int					create_map(t_var *s, char *line, char *tmp);
int					main(void);

#endif
