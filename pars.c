/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:02:26 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/18 10:31:51 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fract-ol"


// void ft_checker_shep(char *shep)
// {
//     int i = 0;
//     while (condition)
//     {
//         /* code */
//     }
    
// }
// void    ft_pars(char *av, char *shep)
// {
//     int i = 0;
//     if (strcmp(av[1], shep) == 0)
        
//     else
//         ft_RTFM();
// }



// typedef struct s_data
// {
//     void *img;
//     void *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// }   t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char *dst;
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }
// // void draw_square(t_data *data, int x, int y, int size, int color)
// // {
// //     int i = 0;
// //     int j = 0;
// //     while (i < size)
// //     {
// //         while (j < size)
// //         {
// //             my_mlx_pixel_put(data, x + i, y + j, color);
// //             j++;
// //         }
// //         i++;
// //     }
// // }
// void draw_square(t_data *data, int x, int y, int size, int color)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             my_mlx_pixel_put(data, x + i, y + j, color);
//         }
//     }
// }
// int main(void)
// {
//     void *mlx_ptr = mlx_init();
//     void *mlx_win;
//     if (!mlx_ptr)
//         return (1);    
//     t_data img;
//     mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "ziad");
//     img.img = mlx_new_image(mlx_ptr, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//     draw_square(&img, 1960, 540, 200, 0xef9f8ff);
//     mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx_ptr);
// }
// #include "minilibx-linux/mlx.h"
// #include <stdlib.h>
// #include <math.h>

// typedef struct s_data
// {
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// } t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char *dst;
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// // Function to calculate the Mandelbrot set
// int mandelbrot(double cr, double ci, int max_iter)
// {
//     double zr = 0.0, zi = 0.0;
//     int iter = 0;

//     while (iter < max_iter)
//     {
//         double zr2 = zr * zr;
//         double zi2 = zi * zi;

//         if (zr2 + zi2 > 4.0)
//             break;

//         double temp = zr2 - zi2 + cr;
//         zi = 2.0 * zr * zi + ci;
//         zr = temp;

//         iter++;
//     }

//     return iter;
// }

// // Function to render the Mandelbrot set
// void render_mandelbrot(t_data *data, int width, int height, int max_iter)
// {
//     for (int y = 0; y < height; y++)
//     {
//         for (int x = 0; x < width; x++)
//         {
//             // Map pixel position to a point in the complex plane
//             double cr = (x - width / 2.0) * 4.0 / width;
//             double ci = (y - height / 2.0) * 4.0 / height;

//             // Calculate the number of iterations
//             int iter = mandelbrot(cr, ci, max_iter);

//             // Map the number of iterations to a color
//             int color = 0;
//             if (iter < max_iter)
//             {
//                 int r = (iter * 5) % 256;
//                 int g = (iter * 10) % 256;
//                 int b = (iter * 20) % 256;
//                 color = (r << 16) | (g << 8) | b;
//             }

//             // Draw the pixel
//             my_mlx_pixel_put(data, x, y, color);
//         }
//     }
// }

// int close_window(void *mlx_ptr)
// {
//     exit(0);
// }

// int key_press(int keycode, void *mlx_ptr)
// {
//     if (keycode == 65307) // ESC key code
//         exit(0);
//     return 0;
// }

// int main(void)
// {
//     void *mlx_ptr = mlx_init();
//     if (!mlx_ptr)
//         return (1);

//     int width = 1980;
//     int height = 1980;

//     void *mlx_win = mlx_new_window(mlx_ptr, width, height, "Mandelbrot Set");
//     if (!mlx_win)
//         return (1);

//     t_data img;
//     img.img = mlx_new_image(mlx_ptr, width, height);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     // Render the Mandelbrot set
//     int max_iter = 100; // Increase for more detail
//     render_mandelbrot(&img, width, height, max_iter);

//     // Display the image in the window
//     mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);

//     // Set up event hooks
//     mlx_hook(mlx_win, 2, 1L << 0, key_press, mlx_ptr); // Key press event
//     mlx_hook(mlx_win, 17, 1L << 0, close_window, mlx_ptr); // Window close event

//     // Keep the window open
//     mlx_loop(mlx_ptr);

//     return 0;
// }
// int main(int ac, char **av)
// {
//     if (ac == 2)
//     {
//         ft_pars();
//     }
//     ft_RTFM();

// }
