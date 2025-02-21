/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:56:08 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/21 12:13:14 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


int ft_zoom(int button , int x, int y, t_fractal *fractal)
{ 
    (void)x;
    (void)y;
    if (button == 4)
        fractal->zoom *= 0.9;
    else if (button == 5)
        fractal->zoom /= 0.9;
    
    // mlx_clear_window(fractal->mlx_ptr, fractal->mlx_win);
    ft_rendering_fractal(fractal);
    return (0);
}

int ft_shift(int keycode, t_fractal *fractal)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
        exit(0);
    }
    if (keycode == 65361)
        fractal->shift_x += (0.3 * fractal->zoom);
    else if (keycode == 65363)
        fractal->shift_x -= (0.3 * fractal->zoom);
    else if (keycode == 65362)
        fractal->shift_y += (0.3 * fractal->zoom);
    else if (keycode == 65364)
        fractal->shift_y -= (0.3 * fractal->zoom);
    else
        return (0);
    mlx_clear_window(fractal->mlx_ptr, fractal->mlx_win);
    ft_rendering_fractal(fractal);
    return (0);
}