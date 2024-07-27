/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:47:15 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:28 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	string(t_fractol *fractol)
{
	fractol->error = "\n\tHello, something is wrong!!\n\nif you want to run Mandelbrot, use it like this.\n\
	./fractol mandelbrot\nAnd if you want to run Julia, use it like this.\n\
	./fractol julia <real number> <imaginary number>\n\
if you want to run Burning Ship, use it like this.\n\
	./fractol ship\n";
	fractol->parse = "Hello, something is wrong with your julia numbers.\n\
The numbers must be correct without \
any characters or multiple decimal points.\n";
}

void	data_init(t_fractol *fractol, int ac, char **av)
{
	fractol->color = 0;
	fractol->zoom = 1.0;
	fractol->iter = 70;
	if (ac > 0 && **av)
	{
		fractol->av = av;
		fractol->ac = ac;
	}
	fractol->x_min = -2.0;
	fractol->y_min = -2.0;
	fractol->x_max = 2.0;
	fractol->y_max = 2.0;
	fractol->arrow = 1.0;
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	data_init(&fractol, ac, av);
	string(&fractol);
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || \
	(ac == 2 && !ft_strcmp(av[1], "ship")) || \
	(ac == 4 && !ft_strcmp(av[1], "julia") && \
	ft_parse(av[2]) && ft_parse(av[3])))
	{
		fractol.title = av[1];
		f_init(&fractol);
		f_build(&fractol);
		mlx_loop(fractol.init);
	}
	else
	{
		if (ac == 4)
		{
			write(2, fractol.parse, 130);
			exit(1);
		}
		write(2, fractol.error, 267);
		exit(1);
	}
}
