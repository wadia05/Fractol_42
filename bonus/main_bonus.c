#include "fractol_bonus.h"

void	verification(t_fractol *frac)
{
	frac->name = "julia";
	init_window(frac);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
		exit(write(2, RED "ENTER A VALID ARGUMENT (julia or mandelbrot)\n",
				53));
	if (ft_strncmp(av[1], "julia", 6) == 0 && ac == 4)
	{
		fractol.cx = ft_atof(av[2]);
		fractol.cy = ft_atof(av[3]);
		verification(&fractol);
	}
	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
	{
		fractol.name = "mandelbrot";
		init_window(&fractol);
	}
	else if (ft_strncmp(av[1], "burningship", 12) == 0 && ac == 2)
	{
		fractol.name = "burningship";
		init_window(&fractol);
	}
	else
	{
		write(2, RED "ERROR: Bad argument\n", 20 + sizeof(RED)-1);
		write(2, YELLOW "./fractol mandelbrot\n", 20 + sizeof(YELLOW)-1);
		write(2, YELLOW "./fractol julia 'num1' 'num2' \n", 32
			+ sizeof(YELLOW)-1);
		exit(write(2, YELLOW "🚨 the value must be between [-2 , 2] 🚨\n", 44
				+ sizeof(YELLOW)-1));
	}
}