/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:20:53 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 18:21:30 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	h_key(t_fractol *frac)
{
	static int	helpp = 0;

	if (helpp == 0)
	{
		help(frac);
		helpp++;
	}
	else
	{
		del_help(frac);
		frac->imgg[0] = mlx_put_string(frac->mlx, "Help : H", 10, 10);
		helpp = 0;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(frac->mlx, frac->img);
		mlx_close_window(frac->mlx);
		exit(write(1, GREEN "EXIT_SUCCESS", 12 + sizeof(GREEN)));
	}
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		frac->max_iterations += 10;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		frac->max_iterations -= 10;
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		h_key(frac);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		init_variable(frac);
	draw(frac);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	if (ydelta > 0)
		frac->zoom *= 1.1;
	else if (ydelta < 0)
		frac->zoom /= 1.1;
	(void)xdelta;
	draw(frac);
}
