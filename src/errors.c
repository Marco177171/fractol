/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:15:43 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/26 12:25:18 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_juliaparamerror(void)
{
	ft_printf("Missing or wrong parameters insert for Julia:");
	ft_printf(" please insert 2 numbers, one real and one imaginary\n");
	ft_printf("Example: ./fractol Julia (*Real num*) (*Imaginary num*)\n");
	exit(0);
}

void	ft_paramerror(void)
{
	ft_printf("Missing or wrong parameter insert");
	ft_printf(": please insert a fractal name and his parameters");
	ft_printf("\nExample: ./fractol Mandelbrot <decimal num>");
	exit(0);
}

void	ft_inputerror(void)
{
	ft_printf("Standard input: ./fractol <name> ...");
	ft_printf("\nYou can choose between:\n");
	ft_printf("- Mandelbrot <iteration> (decimal)\n");
	ft_printf("- Julia <real number> <imaginary number>\n");
	ft_printf("- Tricorn <iteration> (decimal)\n");
	ft_printf("Use arrow keys to move the fractal, press C to change color");
	ft_printf(" and use mouse wheel for in&out zoom\n");
	exit(0);
}

void	ft_limitexceed(void)
{
	ft_printf("iteration limit exceed\n");
}
