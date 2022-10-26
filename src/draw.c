/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:01:11 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:45:49 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpixel(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr
		+ (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_map(t_fractol *fract)
{
	fract->complex.re = fract->x / (WIDTH
			/ (fract->max.re - fract->min.re)) + fract->min.re;
	fract->complex.im = fract->y / (HEIGHT
			/ (fract->max.im - fract->min.im)) + fract->min.im;
}

void	ft_drawfractol(t_fractol *fract)
{
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			ft_map(fract);
			ft_fractolalgoritms(fract->name, fract);
			fract->x++;
		}
		fract->y++;
	}
}

void	ft_draw(t_fractol *fract)
{
	ft_clear(fract);
	ft_drawfractol(fract);
	mlx_put_image_to_window(fract->mlx, fract->window,
		fract->image, 0, 0);
}
