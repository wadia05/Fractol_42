/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:53:14 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 19:53:22 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw(t_fractol *frac)
{
	frac->x = 0;
	frac->y = 0;
	while (frac->y < HEIGHT)
	{
		frac->x = 0;
		while (frac->x < WIDTH)
		{
			if (ft_strncmp(frac->name, "julia", 5) == 0)
				julia_math(frac);
			else if (ft_strncmp(frac->name, "mandelbrot", 10) == 0)
				mandelbrot_math(frac);
			else if (ft_strncmp(frac->name, "burningship", 12) == 0)
				burning_ship_math(frac);
			frac->x++;
		}
		frac->y++;
	}
}
