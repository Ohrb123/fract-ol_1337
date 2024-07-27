/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:47:15 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:02:57 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_complex cnst, t_complex julia, t_fractol *fractol)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	while (i < fractol->iter)
	{
		x = cnst.real * cnst.real;
		y = cnst.imagine * cnst.imagine;
		if (x + y > 4)
			return (i * 0.5);
		cnst.imagine = 2 * cnst.real * cnst.imagine - julia.imagine;
		cnst.real = x - y + julia.real;
		i++;
	}
	return (0);
}

void	string(t_fractol *fractol)
{
	fractol->error = "Hello, something is wrong!!\nif you want to run Mandelbrot, use it like this.\n\
	./fractol mandelbrot\nAnd if you want to run Julia, use it like this.\n\
	./fractol julia <real number> <imaginary number>\n";
	fractol->parse = "Hello, something is wrong with your julia numbers.\n\
The numbers must be correct without \
any characters or multiple decimal points.\n";
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.zoom = 1.0;
	fractol.iter = 50;
	fractol.av = av;
	fractol.ac = ac;
	string(&fractol);
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || \
	(ac == 4 && !ft_strcmp(av[1], "julia") && \
	ft_parse(av[2]) && ft_parse(av[3])))
	{
		fractol.title = av[1];
		(f_init(&fractol), f_build(&fractol), mlx_loop(fractol.init));
	}
	else
	{
		if (ac == 4)
		{
			write(2, fractol.parse, 130);
			exit(1);
		}
		write(2, fractol.error, 197);
		exit(1);
	}
}
