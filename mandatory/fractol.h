/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:25:42 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 18:03:59 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# define MAX_ITER 100

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
	int			x;
	int			y;

	double		cx;
	double		cy;

	double		zx;
	double		zy;
	int			max_iterations;

	double		zoom;

	int			color;
	int			color1;
	int			color2;
	float		fracolor;
	t_color		colors;
	int			colorselect;

	double		sx;
	double		sy;
	double		sx_s;
	double		sy_s;

	mlx_image_t	*imgg[7];

}				t_fractol;

// extra fonction
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atof(char *str);
// inistialisation for window
void			init_window(t_fractol *frac);
void			init_variable(t_fractol *frac);

// drwaw fractal
void			draw(t_fractol *frac);
// math fractal
void			mandelbrot_math(t_fractol *frac);
void			julia_math(t_fractol *frac);

// color
int				interpolatecolor(t_fractol *col);
void			coloring(int i, t_fractol *frac);

// key hooks
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			my_scrollhook(double xdelta, double ydelta, void *param);

void			help(t_fractol *frac);
void			del_help(t_fractol *ff);
#endif
