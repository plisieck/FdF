/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:45:04 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/20 14:45:06 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracesegment1(t_env *e, int *tab)
{
	tab[2] = tab[0];
	tab[0] = tab[2] * 2;
	tab[1] *= 2;
	while (1)
	{
		if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[3]++;
		if (tab[3] == tab[5])
			break ;
		tab[2] = tab[2] - tab[1];
		if (tab[2] < 0)
		{
			tab[4]++;
			tab[2] = tab[2] + tab[0];
		}
	}
}

void	tracesegment2(t_env *e, int *tab)
{
	tab[2] = tab[1];
	tab[1] = tab[2] * 2;
	tab[0] = tab[0] * 2;
	while (1)
	{
		if (e->lst->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[4]++;
		if (tab[4] == tab[6])
			break ;
		tab[2] = tab[2] - tab[0];
		if (tab[2] < 0)
		{
			tab[3]++;
			tab[2] = tab[2] + tab[1];
		}
	}
}

void	tracesegment3(t_env *e, int *tab)
{
	tab[2] = tab[0];
	tab[0] = tab[2] * 2;
	tab[1] = tab[1] * 2;
	while (1)
	{
		if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[3]++;
		if (tab[3] == tab[5])
			break ;
		tab[2] = tab[2] + tab[1];
		if (tab[2] < 0)
		{
			tab[4]--;
			tab[2] = tab[2] + tab[0];
		}
	}
}

void	tracesegment4(t_env *e, int *tab)
{
	tab[2] = tab[1];
	tab[1] = tab[2] * 2;
	tab[0] = tab[0] * 2;
	while (1)
	{
		if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[4]--;
		if (tab[4] == tab[6])
			break ;
		tab[2] = tab[2] + tab[0];
		if (tab[2] > 0)
		{
			tab[3]++;
			tab[2] = tab[2] + tab[1];
		}
	}
}

void	tracesegment5(t_env *e, int *tab)
{
	tab[2] = tab[0];
	tab[0] = tab[2] * 2;
	tab[1] = tab[1] * 2;
	while (1)
	{
		if (e->lst->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[3]--;
		if (tab[3] == tab[5])
			break ;
		tab[2] = tab[2] + tab[1];
		if (tab[2] >= 0)
		{
			tab[4]++;
			tab[2] = tab[2] + tab[0];
		}
	}
}
