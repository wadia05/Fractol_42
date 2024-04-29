/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandl_jul_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:11:54 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 13:19:31 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_size(t_fractol *frac)
{
	if (WIDTH > HEIGHT)
	{
		frac->sx = (float)WIDTH / HEIGHT;
		frac->sx_s = frac->sx;
		frac->sy_s = 0.0;
	}
	else if (WIDTH < HEIGHT)
	{
		frac->sy = (float)WIDTH / HEIGHT;
		frac->sy_s = frac->sx;
		frac->sx_s = 0.0;
	}
}

void	mandelbrot_math(t_fractol *frac)
{
	double	temp;
	int		i;

	i = 0;
	draw_size(frac);
	frac->cx = (((frac->x * 4.0) / (double)WIDTH * frac->sx) - 2.0) * frac->zoom
		- frac->sx_s / 2;
	frac->cy = (((frac->y * 4.0) / (double)HEIGHT / frac->sy) - 2.0)
		* frac->zoom - frac->sy_s / 2;
	frac->zx = 0.0;
	frac->zy = 0.0;
	while (i < frac->max_iterations)
	{
		temp = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * frac->zx * frac->zy + frac->cy;
		frac->zx = temp;
		if ((frac->zx * frac->zx + frac->zy * frac->zy) > 4.0)
			break ;
		i++;
	}
	coloring(i, frac);
}

void	julia_math(t_fractol *frac)
{
	double	temp;
	int		i;

	draw_size(frac);
	frac->zx = (((frac->x * 4.0) / (double)WIDTH * frac->sx) - 2.0) * frac->zoom
		- frac->sx_s / 2;
	frac->zy = (((frac->y * 4.0) / (double)HEIGHT / frac->sy) - 2.0)
		* frac->zoom - frac->sy_s / 2;
	i = 0;
	while (i < frac->max_iterations)
	{
		temp = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * frac->zx * frac->zy + frac->cy;
		frac->zx = temp;
		if ((frac->zx * frac->zx + frac->zy * frac->zy) > 4.0)
			break ;
		i++;
	}
	coloring(i, frac);
}
