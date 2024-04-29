/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:23:19 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 13:23:22 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(t_fractol *frac)
{
	mlx_delete_image(frac->mlx, frac->imgg[0]);
	frac->imgg[5] = mlx_put_string(frac->mlx, "Hide help : H", 10, 10);
	frac->imgg[0] = mlx_put_string(frac->mlx,
			"---------  HELP  Mandatory  ---------", WIDTH / 3.3, 10);
	frac->imgg[1] = mlx_put_string(frac->mlx,
			"welcome to the help Mandatory menu", WIDTH / 3.2, 40);
	frac->imgg[2] = mlx_put_string(frac->mlx, "Zoom : scroll mouse in & out",
			10, 60);
	frac->imgg[3] = mlx_put_string(frac->mlx, "Iterations : + & -", 10, 85);
	frac->imgg[4] = mlx_put_string(frac->mlx, "exit  : ESC  ", 10, 110);
	frac->imgg[6] = mlx_put_string(frac->mlx, "rest  : R  ", 10, 135);
}

void	del_help(t_fractol *ff)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		mlx_delete_image(ff->mlx, ff->imgg[i]);
		i++;
	}
}
