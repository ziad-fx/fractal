/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:17:32 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/21 12:10:27 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bites_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int ft_jolia(double real, double img, void *av2, void *av3)
{
    double real_tmp;
    double c_img;
    double c_real;
    unsigned int i;

    i = 0;
    c_img = atof(av3);
    c_real = atof(av2);

    while (i < ITERATION)
    {
        real_tmp = real * real - img * img + c_real;
        img = 2 * real * img + c_img;
        real = real_tmp;
        if ((real * real + img * img) > 4)
        {
            int r = (i * 5) % 256;       // Red component
            int g = (i * 10) % 256;      // Green component
            int b = (i * 15) % 256;      // Blue component
            return (r << 16) | (g << 8) | b;
        }
            // return (0xFF44FF * i<< 4);
        i++;
    }
    return (0x000000);
}

int ft_mandlbort(t_fractal *fractal)
{
    double real_tmp;
    double img;
    double real;
    int i = 0;

    real = 0;
    img = 0;
    while (i < ITERATION)
    {
        real_tmp = real * real - img * img + fractal->real;
        img = 2 * real * img + fractal->img;
        real = real_tmp;
        if ((real * real + img * img) > 4)
            return (0xFFFFFF * i << 4);
        i++;
    }
    return (0x000000);
}

double ft_maping(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
}

void ft_rendering_fractal(t_fractal *fractal)
{
    int x;
    int y;
    int color;

    x = 0;
    while (x < WITH)
    {
        y = 0;
        while (y < HIGHT)
        {
            fractal->real = ft_maping(x, -2, 2, 0, WITH) * fractal->zoom + fractal->shift_x;
            fractal->img = ft_maping(y, -2, 2, 0, HIGHT) * fractal->zoom + fractal->shift_y;//-2
            if (strcmp(fractal->shep_name, "mandelbrot") == 0)
                color = ft_mandlbort(fractal);
            else if (strcmp(fractal->shep_name, "jolia") == 0)
                color = ft_jolia(fractal->real, fractal->img, fractal->av1, fractal->av2);
            my_mlx_pixel_put(&fractal->data, x, y, color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->data.img_ptr, 0, 0);
}
