/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:49:18 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/21 12:13:53 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void ft_pars_fractal(t_fractal *fractal, int ac, char **av)
{
    if (ac == 2 || ac == 4)
    {
        if (ac == 2 && strcmp(av[1], "mandelbrot") == 0)
        {
            fractal->shep_name = "mandelbrot";
            return ;
        }
        else if (ac == 4 && strcmp(av[1], "jolia") == 0)
        {
            fractal->shep_name = "jolia";
            return ;
        }
    }
    else
        ft_rtfm();
        // exit(1);
}
int main(int ac ,char **av)
{
    
    t_fractal fractal;
    fractal.zoom = 1.0;
    fractal.shift_x = 0.0;
    fractal.shift_y = 0.0;
    fractal.av1 = av[2];
    fractal.av2 = av[3];
    ft_pars_fractal(&fractal, ac , av);
    ft_minilibx_stuff(&fractal);
    ft_rendering_fractal(&fractal);
    mlx_mouse_hook(fractal.mlx_win, ft_zoom, &fractal);
    mlx_key_hook(fractal.mlx_win, ft_shift, &fractal);
    // mlx_clear_window(fractal.mlx_ptr, fractal.mlx_win);
    mlx_loop(fractal.mlx_ptr);
}
