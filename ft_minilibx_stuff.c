/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibx_stuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:28:00 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/20 16:41:44 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void ft_minilibx_stuff(t_fractal *fractal)
{
    // t_data img; remove this 
    fractal->mlx_ptr = mlx_init();
    if (fractal->mlx_ptr == NULL)
        exit(1);
    fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WITH, HIGHT, fractal->shep_name);
    if (fractal->mlx_win == NULL)
    {
        mlx_destroy_display(fractal->mlx_ptr);
        free(fractal->mlx_ptr);
    }



    
    fractal->data.img_ptr = mlx_new_image(fractal->mlx_ptr, WITH, HIGHT);
    if (fractal->data.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
        mlx_destroy_display(fractal->mlx_ptr);
        free(fractal->mlx_ptr);         
        exit(1);
    }
    fractal->data.addr = mlx_get_data_addr(fractal->data.img_ptr, &fractal->data.bites_per_pixel, &fractal->data.line_length, &fractal->data.endian);        
}
