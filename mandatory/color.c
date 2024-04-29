/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:56:02 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 13:57:00 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolatecolor(t_fractol *col)
{
	col->colors.r1 = (col->color1 >> 16) & 0xFF;
	col->colors.g1 = (col->color1 >> 8) & 0xFF;
	col->colors.b1 = col->color1 & 0xFF;
	col->colors.r2 = (col->color2 >> 16) & 0xFF;
	col->colors.g2 = (col->color2 >> 8) & 0xFF;
	col->colors.b2 = col->color2 & 0xFF;
	col->colors.r = col->colors.r1 + col->fracolor * (col->colors.r2
			- col->colors.r1);
	col->colors.g = col->colors.g1 + col->fracolor * (col->colors.g2
			- col->colors.g1);
	col->colors.b = col->colors.b1 + col->fracolor * (col->colors.b2
			- col->colors.b1);
	return ((col->colors.r << 16) | (col->colors.g << 8) | col->colors.b);
}

void	coloring(int i, t_fractol *frac)
{
	frac->color1 = 0x292929FF;
	frac->color2 = 0xFFFFFFFF;
	frac->fracolor = (float)i / frac->max_iterations;
	frac->color = interpolatecolor(frac);
	if (i == frac->max_iterations)
		mlx_put_pixel(frac->img, frac->x, frac->y, 0x000000FF);
	else
		mlx_put_pixel(frac->img, frac->x, frac->y, frac->color);
}
