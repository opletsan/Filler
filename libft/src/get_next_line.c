/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:55:20 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/23 16:55:33 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_gnl	*crt_lst(int fd)
{
	t_gnl	*lst;

	if (!(lst = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	lst->fd = fd;
	lst->buf = ft_strnew(1);
	lst->next = NULL;
	return (lst);
}

static inline t_gnl	*src_lst(int fd, t_gnl *lst)
{
	t_gnl	*tmp;

	tmp = lst;
	while (tmp->next && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		tmp->next = crt_lst(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

static inline int	read_line(t_gnl *f, const int fd, char *buf)
{
	ssize_t	ret;
	char	*tmp;

	ret = 0;
	while (!(ft_strchr(f->buf, '\n')) && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = f->buf;
		if (!(f->buf = ft_strjoin(tmp, buf)))
		{
			ft_strdel(&tmp);
			ft_strdel(&buf);
			return (-1);
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	return (ret);
}

static inline int	contin(char **line, t_gnl *f)
{
	char		*tmp;
	char		*nbuf;
	int			ret;
	static int	len;

	ret = 0;
	if ((tmp = ft_strchr(f->buf, '\n')))
	{
		ret = 1;
		len = ((tmp - f->buf) > 0) ? (tmp - f->buf) : 1;
		if (!(*line = ft_strsub(f->buf, 0, len)) ||
				!(nbuf = ft_strdup(tmp + 1)))
		{
			ft_strdel(&f->buf);
			return (-1);
		}
		ft_strdel(&f->buf);
		f->buf = nbuf;
	}
	else
	{
		*line = ft_strdup(f->buf);
		ft_strdel(&f->buf);
	}
	return ((ret == 0) ? 0 : 1);
}

int					get_next_line(const int fd, char **line)
{
	t_gnl			*f;
	char			*buf;
	static t_gnl	*lst = NULL;

	if (!line || BUF_SIZE <= 0 || !(buf = ft_strnew(BUF_SIZE)) ||
						read(fd, buf, 0) < 0)
		return (-1);
	if (!lst)
		lst = crt_lst(fd);
	if (!(f = src_lst(fd, lst)) || read_line(f, fd, buf) < 0)
	{
		ft_strdel(&f->buf);
		return (-1);
	}
	if (!*f->buf)
	{
		ft_strdel(&f->buf);
		return (0);
	}
	return (contin(line, f));
}
