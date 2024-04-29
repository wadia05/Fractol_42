/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:10:53 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/28 17:26:35 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
int get_num(char k, double num)
{
    num = num * 10.0 + (k - '0');
    return (num);
}
double get_after(char *k)
{
    int i = 0;
    double num = 0.0;
    double fasila = 0.1;
    while (k[i] >= '0' && k[i] <= '9')
    {
        num = num + (k[i] - '0') * fasila ;
        fasila *= 0.1;
        i++;
    }
    if (k[i] == '\0')
        return (num);
    else
    {
        write (2,"error\n",6);
        exit(1);
    }
}

double ft_atof(char *str)
{
    double num = 0.0;
	int n = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+') // Corrected indentation
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = get_num(str[i], num);
        i++;
    }
    if (str[i] == '.')
        i++;
    num += get_after(str+i);
    return num * n;
}