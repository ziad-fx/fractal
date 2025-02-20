/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:17:32 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/20 11:22:51 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

#include "fractal.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bites_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int ft_mandlbort(t_fractal *fractal)
{
    double real_tmp;
    double img;
    double real;
    int i = 0;

    real = 0;
    img = 0;
    while (i < 100)
    {
        real_tmp = real * real - img * img + fractal->real;
        img = 2 * real * img + fractal->img;
        real = real_tmp;
        if ((real * real + img * img) > 4)
            return (0xffffff * i << 5);
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
            fractal->real = ft_maping(x, -2, 2, 0, WITH) * fractal->zoom;
            fractal->img = ft_maping(y, -2, 2, 0, HIGHT) * fractal->zoom;
            color = ft_mandlbort(fractal);
            my_mlx_pixel_put(&fractal->data, x, y, color);
            y++;
        }
        x++;
    }

    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->data.img_ptr, 0, 0);
}
