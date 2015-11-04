/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:45:18 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/22 15:39:35 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *e)
{
	t_points	*new_lst;
	int			t[4];

	rembobine(e);
	e->data = ft_memset(e->data, 0, (HEIGHT * WIDTH) * 4);
	while (e->lst->nxt != NULL)
	{
		if (e->type == 'i')
			trace_iso(e, t);
		else if (e->type == 'p')
			trace_para(e, t);
		centrage(e, t);
		if (e->lst->nxt->y == e->lst->y)
			tracesegment(e, t);
		if ((new_lst = find_down(e->lst)))
			trace_split(e, t, new_lst);
		e->lst = e->lst->nxt;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_menu(e);
}

int			expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

void		reset(t_env *e)
{
	e->zoom = 70;
	e->margin_left = 800;
	e->margin_top = 300;
	e->mult = 1;
	e->angle = 1;
	if (e->type == 'p')
	{
		e->margin_left -= 460;
		e->margin_top -= 100;
		e->angle -= 0.2;
	}
}

void		split_key(int keycode, t_env *e)
{
	if (keycode == 65451)
		e->zoom += 5;
	else if (keycode == 65453 && e->zoom > 5)
		e->zoom -= 5;
	else if (keycode == 65361)
		e->margin_left -= 20;
	else if (keycode == 65363)
		e->margin_left += 20;
	else if (keycode == 65362)
		e->margin_top -= 20;
	else if (keycode == 65364)
		e->margin_top += 20;
	else if (keycode == 65450)
		e->mult += 1;
	else if (keycode == 65455)
		e->mult -= 1;
	else if (keycode == 105)
		norme2(e);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	split_key(keycode, e);
	if (keycode == 112)
		norme1(e);
	else if (keycode == 65456)
		reset(e);
	else if (keycode == 109)
		e->menu = e->menu ? 0 : 1;
	else if (keycode == 65460 && e->type == 'i')
		e->angle -= 0.1;
	else if (keycode == 65462 && e->type == 'i')
		e->angle += 0.1;
	e->data = e->temp;
	draw(e);
	return (0);
}
