/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:45:11 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/20 14:45:13 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracesegment6(t_env *e, int *tab)
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
		tab[2] = tab[2] + tab[0];
		if (tab[2] <= 0)
		{
			tab[3]--;
			tab[2] = tab[2] + tab[1];
		}
	}
}

void	tracesegment7(t_env *e, int *tab)
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
		tab[3]--;
		if (tab[3] == tab[5])
			break ;
		tab[2] = tab[2] - tab[1];
		if (tab[2] >= 0)
		{
			tab[4]--;
			tab[2] = tab[2] + tab[0];
		}
	}
}

void	tracesegment8(t_env *e, int *tab)
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
		tab[2] = tab[2] - tab[0];
		if (tab[2] >= 0)
		{
			tab[3]--;
			tab[2] = tab[2] + tab[1];
		}
	}
}

void	tracesegment9(t_env *e, int *tab)
{
	if (tab[1] > 0)
	{
		while (tab[4] < tab[6])
		{
			if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
				color_pixel(e, tab[3], tab[4], 0x0000FF);
			else
				color_pixel(e, tab[3], tab[4], 0x00FF00);
			tab[4]++;
		}
	}
	else
	{
		while (tab[4] > tab[6])
		{
			if (e->lst->z * e->mult <= 0 && e->lst->nxt->z * e->mult <= 0)
				color_pixel(e, tab[3], tab[4], 0x00FF00);
			else
				color_pixel(e, tab[3], tab[4], 0x00FF00);
			tab[4]--;
		}
	}
}

void	tracesegment10(t_env *e, int *tab)
{
	while (tab[3] > tab[5])
	{
		if (e->lst->z * e->mult <= 0)
			color_pixel(e, tab[3], tab[4], 0x0000FF);
		else
			color_pixel(e, tab[3], tab[4], 0x00FF00);
		tab[3]--;
	}
}
