/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:35:54 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/10 19:28:24 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, t_list *m, size_t fd)
{
	size_t d;
	t_list *l;

	d = -1;
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	if (m)
	{
		while (m && m->next && ((d = ((t_line *)m->next->content)->fd) != fd))
			m = m->next;
		if (d == fd)
		{
			l = (m->next->next);
			ft_lstdelone(&m->next, &ft_bzero);
			m->next = l;
		}
	}
}

static char	**ft_islst(t_list *mylist, size_t fd)
{
	int		err;

	if (!mylist)
		return (NULL);
	err = 0;
	while (mylist)
	{
		if (((t_line *)mylist->content)->fd == fd && (err = 1))
			break ;
		mylist = mylist->next;
	}
	if (err == 0)
		return (NULL);
	if (((t_line *)mylist->content)->lst)
	{
		return (&(((t_line *)mylist->content)->lst));
	}
	return (NULL);
}

static int	ft_lstupd(t_list **mylist, char *rem, size_t fd)
{
	t_line	*myln;
	char	**str;
	char	*tmp;

	rem = ft_strdup(rem);
	str = ft_islst(*mylist, fd);
	if (str && (tmp = *str))
	{
		if (*str && (*str = ft_strjoin(*str, rem)))
			free(tmp);
		else
			*str = ft_strdup(rem);
		free(rem);
	}
	else
	{
		if (!(myln = (t_line *)malloc(sizeof(t_line))))
			return (0);
		myln->fd = fd;
		myln->lst = rem;
		ft_lstadd(mylist, ft_lstnew(myln, sizeof(t_line)));
		free(myln);
	}
	return (1);
}

static int	ft_readln(size_t fd, t_list **mylst, char **line, char *b)
{
	char	*rem;
	char	*re;
	char	**s;
	int		l;

	s = ft_islst(*mylst, fd);
	if ((l = ft_strlen(b)) > 0)
	{
		re = ft_strsub(b, 0, ft_strchr(b, '\n') - b);
		rem = (ft_strchr(b, '\n') + 1);
		if (l && s && (*line = ft_strjoin(*s, re)))
			ft_free(s, 0, 0);
		else
			*line = ft_strdup(re);
		free(re);
		if (rem)
			ft_lstupd(mylst, rem, fd);
		free(b);
	}
	else if (s && **s && (l = 1))
	{
		*line = ft_strdup(*s);
		ft_free(s, *mylst, fd);
	}
	return (l ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	char			**str;
	char			*tmp;
	static t_list	*mylist;
	char			*buf;
	int				rd;

	if ((str = ft_islst(mylist, fd)) && ft_strchr(*str, '\n'))
	{
		tmp = *str;
		*line = ft_strsub(*str, 0, ft_strchr(*str, '\n') - *str);
		*str = ft_strdup(ft_strchr(*str, '\n') + 1);
		free(tmp);
		return (1);
	}
	else if (!(buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1)))
		|| ((rd = read(fd, buf, BUFF_SIZE)) == -1))
		return (-1);
	if (rd && ft_strchr(buf, '\n') == 0 && (ft_lstupd(&mylist, buf, fd)))
	{
		free(buf);
		return (get_next_line(fd, line));
	}
	return (ft_readln(fd, &mylist, line, buf));
}
