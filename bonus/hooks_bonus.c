/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:56:03 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 10:56:04 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	key_arrow(t_fractol *frac, mlx_key_data_t keydata)
{
	double	tmp;

	tmp = frac->new_s_x;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		frac->new_s_x -= 0.1 * (frac->new_ed_x - frac->new_s_x);
		frac->new_ed_x -= 0.1 * (frac->new_ed_x - tmp);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		frac->new_s_x += 0.1 * (frac->new_ed_x - frac->new_s_x);
		frac->new_ed_x += 0.1 * (frac->new_ed_x - tmp);
	}
	tmp = frac->new_s_y;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		frac->new_s_y -= 0.1 * (-frac->new_ed_y + frac->new_s_y);
		frac->new_ed_y -= 0.1 * (-frac->new_ed_y + tmp);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		frac->new_s_y += 0.1 * (-frac->new_ed_y + frac->new_s_y);
		frac->new_ed_y += 0.1 * (-frac->new_ed_y + tmp);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	key_arrow(frac, keydata);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		frac->colorselect++;
		if (frac->colorselect == 5)
			frac->colorselect = 0;
	}
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		frac->max_iterations += 10;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		frac->max_iterations -= 10;
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		h_key(frac);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		init_variable(frac);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(frac->mlx, frac->img);
		mlx_close_window(frac->mlx);
		exit(EXIT_SUCCESS);
	}
	draw(frac);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	if (ydelta > 0)
	{
		mlx_get_mouse_pos(frac->mlx, &frac->mx, &frac->my);
		frac->mx2 = (((frac->mx * (frac->new_ed_x - frac->new_s_x))
					/ (double)WIDTH) + frac->new_s_x);
		frac->my2 = (((frac->my * (-frac->new_s_y + frac->new_ed_y))
					/ (double)HEIGHT) + frac->new_s_y);
		zoom_at_point(frac, ydelta);
	}
	else if (ydelta < 0)
	{
		mlx_get_mouse_pos(frac->mlx, &frac->mx, &frac->my);
		frac->mx2 = (((frac->mx * (frac->new_ed_x - frac->new_s_x))
					/ (double)WIDTH) + frac->new_s_x);
		frac->my2 = (((frac->my * (-frac->new_s_y + frac->new_ed_y))
					/ (double)HEIGHT) + frac->new_s_y);
		zoom_at_point(frac, ydelta);
	}
	(void)xdelta;
	draw(frac);
}
