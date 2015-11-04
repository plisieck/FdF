/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:06:52 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/22 15:23:09 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "libft/libft.h"
# include "/opt/X11/include/X11/X.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT 1600
# define WIDTH 900
# define M mlx_string_put

typedef struct	s_points
{
	int				x;
	int				y;
	int				z;
	struct s_points *nxt;
	struct s_points *prv;
}				t_points;

typedef struct	s_env
{
	void		*mlx;
	char		*temp;
	void		*win;
	void		*img;
	int			zoom;
	int			mult;
	float		angle;
	char		type;
	int			menu;
	int			x_max;
	int			y_max;
	char		*data;
	int			sizeline;
	int			endian;
	int			margin_left;
	int			bpp;
	int			margin_top;
	int			exit;
	t_points	*lst;
}				t_env;

t_points		*find_down(t_points	*lst);
void			color_pixel(t_env *e, int x1, int y1, int color);
void			tracesegment(t_env *e, int *t);
void			tracesegment1(t_env *e, int *tab);
void			tracesegment2(t_env *e, int *tab);
void			tracesegment3(t_env *e, int *tab);
void			tracesegment4(t_env *e, int *tab);
void			tracesegment5(t_env *e, int *tab);
void			tracesegment6(t_env *e, int *tab);
void			tracesegment7(t_env *e, int *tab);
void			tracesegment8(t_env *e, int *tab);
void			tracesegment9(t_env *e, int *tab);
void			tracesegment10(t_env *e, int *tab);
void			tracesegment11(t_env *e, int *tab);
void			tracesegment12(t_env *e, int *tab);
void			tracesegment13(t_env *e, int *tab);
void			put_menu(t_env *e);
void			put_menu2(t_env *e);
void			t_init(t_env *e);
int				check_error(int argc, char **argv);
int				main(int argc, char **argv);
void			rembobine(t_env *e);
void			centrage(t_env *e, int *tab);
void			trace_iso(t_env *e, int t[4]);
void			trace_para(t_env *e, int t[4]);
void			trace_split(t_env *e, int t[4], t_points *new_lst);
int				key_hook(int keycode, t_env *e);
void			split_key(int keycode, t_env *e);
int				expose_hook(t_env *e);
void			reset(t_env *e);
void			draw(t_env *e);
t_points		*get_points(int fd, t_env *e);
t_points		*split_get_points(t_env *e, char **split,
		t_points *lst, int y);
t_points		*split_get(t_env *e);
t_points		*add_element(t_points *lst);
t_points		*creat_lst(void);
void			norme1(t_env *e);
void			norme2(t_env *e);
void			split_main(t_env *e, char **argv);
int				verif_map(char **argv);

#endif
