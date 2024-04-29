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
        write (2,RED"ERROR ARGUMENT\n",16+sizeof(RED)-1);
        exit(1);
    }
}

double ft_atof(char *str)
{
    double num = 0.0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = get_num(str[i], num);
        i++;
    }
    if (str[i] == '.')
        i++;
    num += get_after(str+i);
    return num;
}