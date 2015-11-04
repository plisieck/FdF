/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:07:01 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/22 15:25:13 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracesegment11(t_env *e, int *tab)
{
	tab[1] = tab[6] - tab[4];
	if (tab[1] != 0)
	{
		if (tab[1] > 0)
		{
			if (-tab[0] >= tab[1])
				tracesegment5(e, tab);
			else
				tracesegment6(e, tab);
		}
		else
		{
			if (tab[0] <= tab[1])
				tracesegment7(e, tab);
			else
				tracesegment8(e, tab);
		}
	}
	else
		tracesegment10(e, tab);
}

void	tracesegment12(t_env *e, int *tab)
{
	while (tab[3] < tab[5])
	{
		if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[3]++;
	}
}

void	tracesegment13(t_env *e, int *tab)
{
	tab[1] = tab[6] - tab[4];
	if (tab[1] != 0)
	{
		if (tab[1] > 0)
		{
			if (tab[0] >= tab[1])
				tracesegment1(e, tab);
			else
				tracesegment2(e, tab);
		}
		else
		{
			if (tab[0] >= -tab[1])
				tracesegment3(e, tab);
			else
				tracesegment4(e, tab);
		}
	}
	else
		tracesegment12(e, tab);
}

void	tracesegment(t_env *e, int *t)
{
	int	tab[7];

	tab[3] = t[0];
	tab[4] = t[1];
	tab[5] = t[2];
	tab[6] = t[3];
	tab[0] = tab[5] - tab[3];
	if (tab[0] != 0)
	{
		if (tab[0] > 0)
			tracesegment13(e, tab);
		else
			tracesegment11(e, tab);
	}
	else
	{
		tab[1] = tab[6] - tab[4];
		if (tab[1] != 0)
			tracesegment9(e, tab);
	}
}

void	norme1(t_env *e)
{
	if (e->type == 'i')
	{
		e->margin_left -= 460;
		e->margin_top -= 100;
		e->angle -= 0.2;
	}
	e->type = 'p';
	reset(e);
}
