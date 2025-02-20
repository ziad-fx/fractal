/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:49:18 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/20 11:16:21 by zyahansa         ###   ########.fr       */
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
    ft_pars_fractal(&fractal, ac , av);
    ft_minilibx_stuff(&fractal);
    mlx_hook(fractal.mlx_win, 4, 0, ft_zoom, &fractal);
    mlx_mouse_hook(fractal.mlx_win, ft_zoom, &fractal);
    mlx_clear_window(fractal.mlx_ptr, fractal.mlx_win);
    ft_rendering_fractal(&fractal);
    mlx_loop(fractal.mlx_ptr);
}
