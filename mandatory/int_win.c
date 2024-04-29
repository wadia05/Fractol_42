/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:20:30 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 14:31:35 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_variable(t_fractol *frac)
{
	frac->sx = 1.0;
	frac->sy = 1.0;
	frac->zoom = 1.0;
	frac->max_iterations = MAX_ITER;
}

void	init_window(t_fractol *frac)
{
	frac->mlx = mlx_init(WIDTH, HEIGHT, frac->name, false);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	init_variable(frac);
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	draw(frac);
	frac->imgg[0] = mlx_put_string(frac->mlx, "Help : H", 10, 10);
	mlx_scroll_hook(frac->mlx, my_scrollhook, frac);
	mlx_key_hook(frac->mlx, my_keyhook, frac);
	mlx_loop(frac->mlx);
	mlx_delete_image(frac->mlx, frac->img);
	mlx_close_window(frac->mlx);
	exit(write(1, GREEN "EXIT_SUCCESS", 12 + sizeof(GREEN)));
}
