/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:29:44 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/21 12:01:01 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTAL_H
#define FRACTAL_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


#define WITH 800
#define HIGHT 800
#define ITERATION 40

typedef struct s_data
{
    void *img_ptr;
    void *addr;
    int bites_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct s_fractol
{
    char *shep_name;
    void *mlx_ptr;
    void *mlx_win;
    double  real;
    double img;
    double  zoom;
    double shift_x;
    double shift_y;
    t_data data;
    void *av1;
    void *av2;
}   t_fractal;

//init


int     main(int ac, char **av);
void ft_minilibx_stuff(t_fractal *fractal);

void    ft_pars_fractal(t_fractal *fractal, int ac, char **av);
void ft_rendering_fractal(t_fractal *fractal);
double ft_maping(double unscaled, double new_min, double new_max, double old_min, double old_max);
int ft_mandlbort(t_fractal *fractal);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void ft_pars_fractal(t_fractal *fractal, int ac, char **av);

void    ft_rtfm(void);




int ft_zoom(int button , int x, int y, t_fractal *fractal);
int ft_shift(int keycode, t_fractal *fractal);
int ft_jolia(double real, double img, void *av2, void *av3);

#endif