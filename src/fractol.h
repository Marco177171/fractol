/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:41:45 by ohassyao          #+#    #+#             */
/*   Updated: 2022/10/25 15:51:52 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		600
# define HEIGHT		600

# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "key.h"

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_hsl
{
	int		hue;
	float	sat;
	float	bri;
}	t_hsl;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_fractol
{
	int				argc;
	int				max_iteration;
	int				palette;
	double			zoom;
	double			y;
	double			x;
	char			*name;
	void			*mlx;
	void			*window;
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_complex		min;
	t_complex		max;
	t_complex		start_temp;
	t_complex		end_temp;
	t_complex		complex;
	t_complex		mouse;
	t_complex		julia_const;
}					t_fractol;

t_complex			ft_initcomplex(double re, double im);
t_complex			init_complex(double re, double im);

int					pal_mkg(int p, int i, t_fractol *d);
int					ft_keypress(int key, t_fractol *fract);
int					ft_zoom(int button, int x, int y, t_fractol *t);
int					ft_juliaparamcheck(char *str);
int					ft_paramcheck(char *str);
int					ft_terminate(void);
void				ft_free(t_fractol *fr);
void				ft_clear(t_fractol *fract);
void				ft_initimage(t_fractol *fract);
void				ft_putpixel(t_fractol *data, int x, int y, int color);
void				ft_fractolalgoritms(char *name, t_fractol *fract);
void				ft_mandelbrot(t_fractol *fract);
void				ft_julia(t_fractol *fract);
void				ft_tricorn(t_fractol *fract);
void				ft_setdefault(t_fractol *fract, char **argv);
void				ft_juliainit(t_fractol *fract, char **argv);
void				ft_standardinit(t_fractol *fract, char **argv);
void				ft_drawfractol(t_fractol *fract);
void				ft_draw(t_fractol *fract);
void				ft_juliaparamerror(void);
void				ft_paramerror(void);
void				ft_inputerror(void);
void				ft_limitexceed(void);
#endif
