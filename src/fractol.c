/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:01:43 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/10 17:37:06 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = ft_initcomplex(fractol->complex.re, fractol->complex.im);
	while (iteration < fractol->max_iteration)
	{
		z = ft_initcomplex(
				((z.re * z.re) - (z.im * z.im)) + fractol->complex.re,
				2.0 * z.re * z.im + fractol->complex.im);
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			ft_putpixel(fractol, fractol->x, fractol->y,
				(pal_mkg(fractol->palette, iteration, fractol)));
			break ;
		}
		iteration++;
	}
}

void	ft_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = ft_initcomplex(fractol->complex.re, fractol->complex.im);
	while (iteration < fractol->max_iteration)
	{
		z = ft_initcomplex(
				(z.re * z.re - z.im * z.im) + fractol->julia_const.re,
				2.0 * z.re * z.im + fractol->julia_const.im);
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			ft_putpixel(fractol, fractol->x, fractol->y,
				(pal_mkg(fractol->palette, iteration, fractol)));
			break ;
		}
		iteration++;
	}
}

void	ft_tricorn(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = ft_initcomplex(fractol->complex.re, fractol->complex.im);
	while (iteration < fractol->max_iteration)
	{
		z = ft_initcomplex(
				(z.re * z.re - z.im * z.im) + fractol->complex.re,
				-2.0 * z.re * z.im + fractol->complex.im);
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			ft_putpixel(fractol, fractol->x, fractol->y,
				(pal_mkg(fractol->palette, iteration, fractol)));
			break ;
		}
		iteration++;
	}
}

void	ft_fractolalgoritms(char *name, t_fractol *fract)
{
	if (!ft_strncmp("Mandelbrot", name, 10))
		ft_mandelbrot(fract);
	else if (!ft_strncmp("Julia", name, 5))
		ft_julia(fract);
	else if (!ft_strncmp("Tricorn", name, 7))
		ft_tricorn(fract);
	else
		ft_inputerror();
}
