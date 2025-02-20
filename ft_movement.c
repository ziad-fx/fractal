/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:56:08 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/20 11:20:30 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


int ft_zoom(int button , int x, int y, t_fractal *fractal)
{ 
    (void)x;
    (void)y;
    printf("%d\n",button);
    if (button == 4)
        fractal->zoom *= 0.7;
    else if (button == 5)
        fractal->zoom *= 1.1;
    printf("%f\n",fractal->zoom);
    ft_rendering_fractal(fractal);
    return (0);
}
