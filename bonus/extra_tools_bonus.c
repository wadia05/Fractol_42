/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:36:52 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/08 10:37:42 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((n > i) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	get_num(char k, double num)
{
	num = num * 10.0 + (k - '0');
	return (num);
}

double	get_after(char *k)
{
	int		i;
	double	num;
	double	fasila;

	i = 0;
	num = 0.0;
	fasila = 0.1;
	if (k[i] == '.' && (k[i + 1] == '\0'))
		exit(write(1, "error", 5));
	else
		i++;
	while (k[i] >= '0' && k[i] <= '9')
	{
		num = num + (k[i] - '0') * fasila;
		fasila *= 0.1;
		i++;
	}
	while (k[i] == ' ' || k[i] == '\t')
		i++;
	if (k[i] == '\0')
		return (num);
	else
		exit(write(2, RED "ERROR ARGUMENT\n", 16 + sizeof(RED) - 1));
}

double	ft_atof(char *str)
{
	double	num;
	int		i;
	int		nega;

	num = 0.0;
	i = 0;
	nega = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		exit(write(1, "error", 5));
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			nega = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = get_num(str[i], num);
		i++;
	}
	if (str[i] == '.' && (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9')))
		i++;
	num += get_after(str + i - 1);
	return (num * nega);
}
