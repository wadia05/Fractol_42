#include "fractol_bonus.h"

void mandelbrot_math(t_fractol *frac)
{
    double temp;
    int i;

    i = 0;
    // printf("sdas");
    frac->cx = ((((frac->x * (frac->new_ed_x - frac->new_s_x)) / (double)WIDTH)   + frac->new_s_x));
    frac->cy = ((((frac->y * (frac->new_ed_y - frac->new_s_y)) / (double)HEIGHT)  + frac->new_s_y));
    frac->zx = 0.0;
    frac->zy = 0.0;
    //z = z^2 + c

    while (i < frac->max_iterations)
    {
		temp = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * frac->zx * frac->zy + frac->cy;
		frac->zx = temp;
		if ((frac->zx * frac->zx + frac->zy * frac->zy) > 4.0)
			break ;
		i++;
    }
    
    coloring( i, frac);
}
void julia_math(t_fractol *frac)
{

    double temp;
    int i;

    i = 0;
    frac->zx = ((((frac->x * (frac->new_ed_x - frac->new_s_x)) / (double)WIDTH)   + frac->new_s_x));
    frac->zy = ((((frac->y * (frac->new_ed_y - frac->new_s_y)) / (double)HEIGHT)  + frac->new_s_y));
    while (i < frac->max_iterations)
    {
        temp = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
        frac->zy = 2 * frac->zx * frac->zy + frac->cy;
        frac->zx = temp;
        if ((frac->zx * frac->zx + frac->zy * frac->zy) > 4.0)
            break;
        i++;
    }
    coloring( i, frac);
}

void burning_ship_math(t_fractol *frac)
{
    double temp;
    int i;

    i = 0;
    frac->cx = ((((frac->x * (frac->new_ed_x - frac->new_s_x)) / (double)WIDTH) + frac->new_s_x));
    frac->cy = ((((frac->y * (frac->new_ed_y - frac->new_s_y)) / (double)HEIGHT) + frac->new_s_y));
    frac->zx = 0.0;
    frac->zy = 0.0;

    while (i < frac->max_iterations)
    {
        temp = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
        frac->zy = 2 * fabs(frac->zx * frac->zy) + frac->cy;
        frac->zx = fabs(temp);
        if ((frac->zx * frac->zx + frac->zy * frac->zy) > 4.0)
            break;
        i++;
    }
    coloring(i, frac);
}


