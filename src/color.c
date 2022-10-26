/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:44:05 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:44:58 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	huetorgb(float v1, float v2, float vH)
{
	if (vH < 0)
		vH += 1;
	if (vH > 1)
		vH -= 1;
	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1)
		return (v2);
	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return (v1);
}

t_rgb	hlstorgb(t_hsl hsl)
{
	t_rgb	rgb;
	float	v1;
	float	v2;
	float	hue;

	hue = (float)hsl.hue / 360;
	v2 = (hsl.bri + hsl.sat) - (hsl.bri * hsl.sat);
	v1 = 2 * hsl.bri - v2;
	rgb.r = (unsigned char)(255 * huetorgb(v1, v2, hue + (1.0f / 3)));
	rgb.g = (unsigned char)(255 * huetorgb(v1, v2, hue));
	rgb.b = (unsigned char)(255 * huetorgb(v1, v2, hue - (1.0f / 3)));
	return (rgb);
}

int	colosr(float i, int p)
{
	t_hsl	hsl;
	t_rgb	rgb;
	int		x;

	if (p == 2)
		hsl.hue = 208 - ((int)i * 10);
	else if (p == 1)
		hsl.hue = 300 - ((int)i * 10);
	else
		hsl.hue = 266 - ((int)i * 10);
	hsl.sat = 1.0f;
	hsl.bri = 0.50f;
	rgb = hlstorgb(hsl);
	x = ((int)rgb.r << 16 | (int)rgb.g << 8 | (int)rgb.b);
	return (x);
}

int	pal_mkg(int p, int i, t_fractol *d)
{
	(void)d;
	if (p == 0)
		return (colosr(i, 2));
	if (p == 1)
		return (colosr(i, 1));
	if (p == 2)
		return (colosr(i, 0));
	return (0);
}
