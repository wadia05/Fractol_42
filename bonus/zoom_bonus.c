/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:34:44 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 10:34:45 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom_at_point(t_fractol *zoom, double delta)
{
	if (delta > 0)
	{
		zoom->tmp = zoom->new_s_x;
		zoom->new_s_x += (zoom->mx2 - zoom->new_s_x) * zoom->zoom;
		zoom->new_ed_x -= (zoom->new_ed_x - zoom->mx2) * zoom->zoom;
		zoom->tmp = zoom->new_s_y;
		zoom->new_s_y += (zoom->my2 - zoom->new_s_y) * zoom->zoom;
		zoom->new_ed_y -= (zoom->new_ed_y - zoom->my2) * zoom->zoom;
	}
	else
	{
		zoom->tmp = zoom->new_s_x;
		zoom->new_s_x -= (zoom->mx2 - zoom->new_s_x) * zoom->zoom;
		zoom->new_ed_x += (zoom->new_ed_x - zoom->mx2) * zoom->zoom;
		zoom->tmp = zoom->new_s_y;
		zoom->new_s_y -= (zoom->my2 - zoom->new_s_y) * zoom->zoom;
		zoom->new_ed_y += (zoom->new_ed_y - zoom->my2) * zoom->zoom;
	}
}
