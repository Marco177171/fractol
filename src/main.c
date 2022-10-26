/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:02:25 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:51:15 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if (argc > 2 && argc < 5)
	{
		fr.mlx = mlx_init();
		fr.name = argv[1];
		fr.argc = argc;
		ft_initimage(&fr);
		fr.window = mlx_new_window(fr.mlx, WIDTH, HEIGHT, fr.name);
		ft_setdefault(&fr, argv);
		ft_fractolalgoritms(fr.name, &fr);
		mlx_hook(fr.window, 2, 0, ft_keypress, &fr);
		mlx_hook(fr.window, 4, 0, ft_zoom, &fr);
		mlx_hook(fr.window, 17, 0, ft_terminate, &fr);
		ft_draw(&fr);
		mlx_loop(fr.mlx);
	}
	else
		ft_inputerror();
	return (0);
}
