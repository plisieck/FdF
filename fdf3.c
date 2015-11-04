/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:44:52 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/22 15:25:17 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_menu2(t_env *e)
{
	M(e->mlx, e->win, HEIGHT - 170, 10, 0xFFFFFF, "_________________________");
	M(e->mlx, e->win, HEIGHT - 115, 28, 0x00FF00, "M E N U");
	M(e->mlx, e->win, HEIGHT - 170, 35, 0xFFFFFF, "_________________________");
	M(e->mlx, e->win, HEIGHT - 170, 55, 0xFFFFFF, "Zoom : ");
	M(e->mlx, e->win, HEIGHT - 170, 55, 0x00FF00, "                      + -");
	M(e->mlx, e->win, HEIGHT - 170, 70, 0xFFFFFF, "Deplacement :");
	M(e->mlx, e->win, HEIGHT - 170, 70, 0x00FF00, "                  Fleches");
	M(e->mlx, e->win, HEIGHT - 170, 85, 0xFFFFFF, "Modifier Altitude :");
	M(e->mlx, e->win, HEIGHT - 170, 85, 0x00FF00, "                      * /");
	M(e->mlx, e->win, HEIGHT - 170, 100, 0xFFFFFF, "Rotation :");
	M(e->mlx, e->win, HEIGHT - 170, 100, 0x00FF00, "                      4 6");
	M(e->mlx, e->win, HEIGHT - 170, 115, 0xFFFFFF, "Projection :");
	M(e->mlx, e->win, HEIGHT - 170, 115, 0x00FF00, "                      i p");
	M(e->mlx, e->win, HEIGHT - 170, 130, 0xFFFFFF, "Reset:");
	M(e->mlx, e->win, HEIGHT - 170, 130, 0x00FF00, "                        0");
	M(e->mlx, e->win, HEIGHT - 170, 145, 0xFFFFFF, "Masquer le menu :");
	M(e->mlx, e->win, HEIGHT - 170, 145, 0x00FF00, "                        m");
	M(e->mlx, e->win, HEIGHT - 170, 160, 0xFFFFFF, "Quitter :");
	M(e->mlx, e->win, HEIGHT - 170, 160, 0x00FF00, "                    Echap");
	M(e->mlx, e->win, HEIGHT - 170, 172, 0xFFFFFF, "_________________________");
}

void		put_menu(t_env *e)
{
	if (e->type == 'i')
		M(e->mlx, e->win, 7, 18, 0xFFFFFF, "Projection Isometrique");
	else if (e->type == 'p')
		M(e->mlx, e->win, 7, 18, 0xFFFFFF, "Projection Parallele");
	M(e->mlx, e->win, HEIGHT - (HEIGHT - 8), WIDTH - 8, 0xFFFFFF,
			ft_strjoin("Altitude : ", ft_itoa((e->mult / 1))));
	M(e->mlx, e->win, HEIGHT - 75, WIDTH - 8, 0xFFFFFF, ft_strjoin
			(ft_strjoin("Zoom : ", ft_itoa((e->zoom * 100) / 70)), "%"));
	if (e->menu)
		put_menu2(e);
	else
		M(e->mlx, e->win, 1680, 20, 0xFFFFFF,
				"Appuyez sur 'm' pour afficher le MENU.");
}

t_points	*find_down(t_points *lst)
{
	int	x;
	int	y;

	x = lst->x;
	y = lst->y;
	while (lst->nxt != NULL && lst->y != y + 1)
		lst = lst->nxt;
	while (lst->nxt != NULL && lst->x != x)
		lst = lst->nxt;
	if (lst->y != y + 1)
		return (NULL);
	return (lst);
}

void		color_pixel(t_env *e, int x1, int y1, int color)
{
	if (x1 >= 0 && y1 > 0 && x1 < HEIGHT && y1 <= WIDTH)
	{
		e->data[(y1 * e->sizeline) + (4 * x1) + 2] = color >> 16;
		e->data[(y1 * e->sizeline) + (4 * x1) + 1] = color >> 8;
		e->data[(y1 * e->sizeline) + (4 * x1)] = color;
	}
}

void		norme2(t_env *e)
{
	if (e->type == 'p')
	{
		e->margin_left += 460;
		e->margin_top += 100;
		e->angle += 0.2;
	}
	e->type = 'i';
}
