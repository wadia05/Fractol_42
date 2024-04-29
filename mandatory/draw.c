/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:54:55 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 13:55:06 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractol *frac)
{
	frac->x = 0;
	frac->y = 0;
	while (frac->y < frac->mlx->height)
	{
		frac->x = 0;
		while (frac->x < frac->mlx->width)
		{
			if (ft_strncmp(frac->name, "julia", 5) == 0)
				julia_math(frac);
			else if (ft_strncmp(frac->name, "mandelbrot", 10) == 0)
				mandelbrot_math(frac);
			frac->x++;
		}
		frac->y++;
	}
}
