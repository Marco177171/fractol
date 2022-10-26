/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:04:51 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/26 13:01:38 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_paramcheck(char *str)
{
	int	counter;
	int	len;

	len = 0;
	counter = 0;
	len = ft_strlen(str);
	while (counter < len)
	{
		if ((*str >= '0' && *str <= '9'))
		{
			str++;
			counter++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_juliaparamcheck(char *str)
{
	int	counter;
	int	len;

	len = 0;
	counter = 0;
	len = ft_strlen(str);
	while (counter < len)
	{
		if ((*str >= '0' && *str <= '9')
			|| (*str == '-' || *str == '.'))
		{
			counter++;
			str++;
		}
		else
			return (1);
	}
	return (0);
}

void	ft_standardinit(t_fractol *fractol, char **argv)
{
	if (!ft_paramcheck(argv[2])
		&& (ft_atoi(argv[2]) >= 5 && ft_atoi(argv[2]) <= 200))
			fractol->max_iteration = ft_atoi(argv[2]);
	else
		ft_paramerror();
}

void	ft_juliainit(t_fractol *fractol, char **argv)
{
	if (!ft_juliaparamcheck(argv[2])
		&& !ft_juliaparamcheck(argv[3]))
		fractol->julia_const
			= ft_initcomplex(ft_strtod(argv[2]), ft_strtod(argv[3]));
	else
		ft_juliaparamerror();
}

void	ft_setdefault(t_fractol *fractol, char **argv)
{
	if (fractol->argc == 4)
	{
		fractol->max_iteration = 30;
		ft_juliainit(fractol, argv);
	}
	else if (fractol->argc == 3)
		ft_standardinit(fractol, argv);
	else
		ft_inputerror();
	fractol->min = ft_initcomplex(-2.0, -2.0);
	fractol->max = ft_initcomplex(2, 2);
	fractol->mouse = ft_initcomplex(0, 0);
	fractol->palette = 2;
}
