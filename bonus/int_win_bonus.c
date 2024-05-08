/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_win_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:37 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 11:00:38 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_variable(t_fractol *var)
{
	var->new_s_x = -2;
	var->new_ed_x = 2;
	var->new_s_y = -2;
	var->new_ed_y = 2;
	var->max_iterations = MAX_ITER;
	var->nabil[0] = 0x292929FF;
	var->nabil[1] = 0xFFFFFFFF;
	var->nabil[2] = 0x000000FF;
	var->nabil[3] = 0xFFFFFFFF;
	var->nabil[4] = 0xFF00FFFF;
	var->nabil[6] = 0x09F900FF;
	var->nabil[7] = 0xBBAA00FF;
	var->zoom = 0.5;
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
