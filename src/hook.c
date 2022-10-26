/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:33:41 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:54:11 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(int button, int x, int y, t_fractol *t)
{
	double	zoom;

	zoom = 0;
	t->mouse = ft_initcomplex(
			x / (WIDTH / (t->max.re - t->min.re)) + t->min.re,
			y / (HEIGHT / (t->max.im - t->min.im)) * -1 + t->max.im);
	if (button == 5)
		zoom = 1.05;
	else if (button == 4)
		zoom = 0.95;
	else
		return (0);
	t->min.re = t->mouse.re + ((t->min.re - t->mouse.re) * zoom);
	t->max.re = t->mouse.re + ((t->max.re - t->mouse.re) * zoom);
	t->min.im = t->mouse.im + ((t->min.im - t->mouse.im) * zoom);
	t->max.im = t->mouse.im + ((t->max.im - t->mouse.im) * zoom);
	ft_draw(t);
	return (0);
}

void	ft_move(int key, t_fractol *fractol)
{
	double	re;
	double	im;

	re = (fractol->max.re - fractol->min.re) * 0.1;
	im = (fractol->max.im - fractol->min.im) * 0.1;
	if (key == LEFT)
	{
		fractol->min.re -= re;
		fractol->max.re -= re;
	}
	else if (key == RIGHT)
	{
		fractol->min.re += re;
		fractol->max.re += re;
	}
	else if (key == DOWN)
	{
		fractol->min.im += im;
		fractol->max.im += im;
	}
	else if (key == UP)
	{
		fractol->min.im -= im;
		fractol->max.im -= im;
	}
}

void	ft_changeiteration(int key, t_fractol *fractol)
{
	if (key == PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration <= 200)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
		else
			ft_limitexceed();
	}
	if (key == MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
		else if (fractol->max_iteration >= 0)
			fractol->max_iteration -= 1;
		else
			ft_limitexceed();
	}
}

void	ft_switch(t_fractol *d)
{
	if (d->palette == 0)
		d->palette = 1;
	else if (d->palette == 1)
		d->palette = 2;
	else
		d->palette = 0;
}

int	ft_keypress(int key, t_fractol *fractol)
{
	if (key == ESC)
		ft_terminate();
	else if (key == MINUS || key == PLUS)
		ft_changeiteration(key, fractol);
	else if (key == LEFT || key == RIGHT
		|| key == UP || key == DOWN)
		ft_move(key, fractol);
	else if (key == C)
		ft_switch(fractol);
	ft_draw(fractol);
	return (0);
}
