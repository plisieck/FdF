/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:06:45 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/23 16:49:03 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		t_init(t_env *e)
{
	e->x_max = 0;
	e->y_max = 0;
	e->exit = 0;
	e->zoom = 70;
	e->margin_left = 800;
	e->margin_top = 300;
	e->mult = 1;
	e->type = 'i';
	e->menu = 1;
	e->angle = 1;
}

int			check_error(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" file\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error: Opening File Failed\n");
		return (-1);
	}
	return (fd);
}

int			verif_map(char **argv)
{
	char	buf[50];
	int		i;
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	read(fd, buf, 49);
	i = 0;
	while (i < 48)
	{
		if (buf[i] != '-' && !ft_isspace(buf[i]) && !(ft_isdigit(buf[i])))
		{
			ft_putchar(buf[i]);
			ft_putstr("error: Invalid File\n");
			return (-1);
		}
		i++;
	}
	close(fd);
	return (0);
}

void		split_main(t_env *e, char **argv)
{
	e->win = mlx_new_window(e->mlx, HEIGHT, WIDTH, argv[1]);
	e->img = mlx_new_image(e->mlx, HEIGHT, WIDTH);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	e->temp = ft_memset(e->data, 0, (HEIGHT * WIDTH) * 4);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_env	e;

	if (verif_map(argv) == -1 || (fd = check_error(argc, argv)) == -1)
		return (-1);
	t_init(&e);
	e.lst = get_points(fd, &e);
	if (e.exit || e.lst == NULL)
	{
		ft_putstr("error: Opening File Failed\n");
		return (-1);
	}
	rembobine(&e);
	e.mlx = mlx_init();
	if (e.mlx == NULL)
	{
		ft_putstr("error: Invalid env\n");
		return (-1);
	}
	split_main(&e, argv);
	mlx_hook(e.win, KeyPress, KeyPressMask, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	close(fd);
	return (0);
}
