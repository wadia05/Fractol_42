/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:59:04 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 19:59:07 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	help(t_fractol *frac)
{
	mlx_delete_image(frac->mlx, frac->imgg[0]);
	frac->imgg[0] = mlx_put_string(frac->mlx, "Hide help : H", 10, 10);
	frac->imgg[1] = mlx_put_string(frac->mlx,
			"---------  HELP  BONUS  ---------", WIDTH / 3.0, 10);
	frac->imgg[2] = mlx_put_string(frac->mlx,
			"welcome to the help bonus menu", WIDTH / 2.9, 40);
	frac->imgg[3] = mlx_put_string(frac->mlx,
			"Zoom : scroll in & out folowing mouse", 10, 85);
	frac->imgg[4] = mlx_put_string(frac->mlx, "moves : the arrow keys", 10,
			110);
	frac->imgg[5] = mlx_put_string(frac->mlx, "Iterations : + & -", 10, 135);
	frac->imgg[6] = mlx_put_string(frac->mlx, "Color : P", 10, 160);
	frac->imgg[7] = mlx_put_string(frac->mlx, "rest  : R  ", 10, 185);
	frac->imgg[8] = mlx_put_string(frac->mlx, "exit  : ESC  ", 10, 210);
}

void	del_help(t_fractol *ff)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		mlx_delete_image(ff->mlx, ff->imgg[i]);
		i++;
	}
}
