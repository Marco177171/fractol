/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:19:36 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/26 14:28:43 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_vars(double *d, int *n, int *dig, int *dec)
{
	*d = 0.0;
	*n = 0;
	*dig = 0;
	*dec = 0;
}

static void	ft_check_sign(char **s, int *negptr)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*negptr = 1;
		(*s)++;
	}
}

double	ft_negtopos(int negative, double nbr)
{
	if (negative == 1)
		nbr = nbr * -1;
	return (nbr);
}

double	ft_strtod(char *s)
{
	double	nbr;
	int		negative;
	int		digits;
	int		decimals;

	while (*s == ' ')
		s++;
	ft_init_vars(&nbr, &negative, &digits, &decimals);
	ft_check_sign(&s, &negative);
	while (ft_isdigit(*s) || (digits++))
		nbr = nbr * 10.0 + (*(s++) - '0');
	if (*s == '.')
	{
		s++;
		while (ft_isdigit(*s) && ++digits && ++decimals)
		{
			nbr = nbr * 10.0 + (*s - '0');
			s++;
		}
	}
	while (decimals--)
		nbr /= 10.0;
	nbr = ft_negtopos(negative, nbr);
	return (nbr);
}
