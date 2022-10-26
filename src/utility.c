/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:03:40 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:52:45 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_terminate(void)
{
	exit(0);
	return (0);
}

void	ft_clear(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx, fract->image);
	ft_initimage(fract);
}

void	ft_initimage(t_fractol *fract)
{
	fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->data_addr = mlx_get_data_addr(
			fract->image,
			&(fract->bits_per_pixel),
			&(fract->size_line),
			&(fract->endian));
}

t_complex	ft_initcomplex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
