/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:44:59 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/20 17:18:36 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rembobine(t_env *e)
{
	while (e->lst->prv != NULL)
		e->lst = e->lst->prv;
}

void		centrage(t_env *e, int *tab)
{
	tab[0] += e->margin_left;
	tab[1] += e->margin_top;
	tab[2] += e->margin_left;
	tab[3] += e->margin_top;
}

void		trace_iso(t_env *e, int t[4])
{
	double	c;
	double	s;

	c = cos(e->angle);
	s = sin(e->angle);
	t[0] = (0.5 * e->lst->x * (c) - 0.5 * e->lst->y * s) * e->zoom;
	t[1] = 0 - e->lst->z * e->mult + ((0.5 / 2) *
			e->lst->x * s + (0.5 / 2) * e->lst->y * c) * e->zoom;
	t[2] = (0.5 * e->lst->nxt->x * (c) - 0.5 * e->lst->nxt->y * s) * e->zoom;
	t[3] = 0 - e->lst->nxt->z * e->mult + ((0.5 / 2)
			* e->lst->nxt->x * s + (0.5 / 2) * e->lst->nxt->y * c) * e->zoom;
}

void		trace_para(t_env *e, int t[4])
{
	double	c;
	double	s;

	c = cos(e->angle);
	s = sin(e->angle);
	t[0] = e->lst->x * e->zoom * s + 0.5 * e->lst->z * e->mult;
	t[1] = e->lst->y * e->zoom * c + (0.5 / 2) * e->lst->z * e->mult;
	t[2] = e->lst->nxt->x * e->zoom * s + 0.5 * e->lst->nxt->z * e->mult;
	t[3] = e->lst->nxt->y * e->zoom * c + (0.5 / 2) * e->lst->nxt->z * e->mult;
}

void		trace_split(t_env *e, int t[4], t_points *new_lst)
{
	double	c;
	double	s;

	c = cos(e->angle);
	s = sin(e->angle);
	if (e->type == 'i')
	{
		t[2] = (0.5 * new_lst->x * (c) - 0.5 * new_lst->y
				* s) * e->zoom + e->margin_left;
		t[3] = 0 - new_lst->z * e->mult + ((0.5 / 2) * new_lst->x
				* s + (0.5 / 2) * new_lst->y * c) * e->zoom + e->margin_top;
	}
	else if (e->type == 'p')
	{
		t[2] = new_lst->x * e->zoom * s + 0.5 *
			new_lst->z * e->mult + e->margin_left;
		t[3] = new_lst->y * e->zoom * c + (0.5 / 2) *
			new_lst->z * e->mult + e->margin_top;
	}
	tracesegment(e, t);
}
