/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:45:25 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/21 14:58:38 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_points	*creat_lst(void)
{
	t_points	*lst;

	lst = (t_points*)malloc(sizeof(t_points));
	lst->x = 0;
	lst->y = 0;
	lst->z = 0;
	lst->nxt = NULL;
	lst->prv = NULL;
	return (lst);
}

t_points	*add_element(t_points *lst)
{
	t_points *new_lst;

	new_lst = creat_lst();
	if (lst == NULL)
		return (new_lst);
	new_lst->prv = lst;
	lst->nxt = new_lst;
	return (new_lst);
}

t_points	*split_get(t_env *e)
{
	t_points	*lst;

	lst = NULL;
	ft_putstr("error: Invalid file\n");
	e->exit = 1;
	return (lst);
}

t_points	*split_get_points(t_env *e, char **split,
		t_points *lst, int y)
{
	int			i;

	i = 0;
	while (split[i])
	{
		lst = add_element(lst);
		lst->x = i;
		lst->y = y;
		lst->z = ft_atoi(split[i]);
		if (lst->x > e->x_max)
			e->x_max = i;
		if (lst->y > e->y_max)
			e->y_max = y;
		i++;
	}
	return (lst);
}

t_points	*get_points(int fd, t_env *e)
{
	int			y;
	t_points	*lst;
	char		*line;
	char		**split;

	y = 0;
	lst = NULL;
	while (get_next_line(fd, &line))
	{
		if (!line)
		{
			return (lst = split_get(e));
		}
		split = ft_strsplit(line, ' ');
		lst = split_get_points(e, split, lst, y);
		y++;
	}
	e->x_max += 1;
	e->y_max += 1;
	return (lst);
}
