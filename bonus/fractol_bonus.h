/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:55:08 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 19:58:06 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 60

typedef struct s_color
{
	int			r1;
	int			g1;
	int			b1;

	int			r2;
	int			g2;
	int			b2;

	int			r;
	int			g;
	int			b;

}				t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*name;
	int32_t		x;
	int32_t		y;

	double		new_s_x;
	double		new_ed_x;
	double		new_s_y;
	double		new_ed_y;

	double		cx;
	double		cy;


	double		zx;
	double		zy;
	int32_t		max_iterations;

	double		zoom;

	int			color;
	int			color1;
	int			color2;
	float		fracolor;
	t_color		colors;
	int			nabil[10];
	int			colorselect;

	int			mx;
	int			my;
	double		mx2;
	double		my2;

	double		tmp;
	mlx_image_t	*imgg[9];

}				t_fractol;

// extra function 😇
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atof(char *str);
// initialization for window
void			init_window(t_fractol *frac);
void			init_variable(t_fractol *var);

// draw fractal
void			draw(t_fractol *frac);
// math fractal
void			mandelbrot_math(t_fractol *frac);
void			julia_math(t_fractol *frac);
void burning_ship_math(t_fractol *frac);

// color
int				interpolateColor(t_fractol *col);
void			coloring(int i, t_fractol *frac);

// key hooks
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			my_keyhook_arrew(mlx_key_data_t keydata, void *param);

// help_user
void			help(t_fractol *frac);
void			del_help(t_fractol *ff);

// zoom_follow_mouse
void			zoom_at_point(t_fractol *zoom, double der);

#endif