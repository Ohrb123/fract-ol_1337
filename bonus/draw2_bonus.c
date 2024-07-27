/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:04:48 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:23 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	change_color(int i)
{
	int	red;
	int	green;
	int	blue;

	red = (i * 20) % 256;
	green = (i * 0) % 256;
	blue = (i * 15) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	help_drawer(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->init, fractol->window, \
	fractol->image.image, 0, 0);
	mlx_string_put(fractol->init, fractol->window, 80, 10, 0xF3F3F3,
		"Controls");
	mlx_string_put(fractol->init, fractol->window, 30, 40, 0xF3F3F3,
		"Reset          --> Space");
	mlx_string_put(fractol->init, fractol->window, 30, 70, 0xF3F3F3,
		"Color Shift    --> Tab");
	mlx_string_put(fractol->init, fractol->window, 30, 100, 0xF3F3F3,
		"Move           --> Arrows");
	mlx_string_put(fractol->init, fractol->window, 30, 130, 0xF3F3F3,
		"Zoom           --> Scroll");
	mlx_string_put(fractol->init, fractol->window, 30, 160, 0xF3F3F3,
		"Iterations     --> +/-");
	mlx_string_put(fractol->init, fractol->window, 30, 190, 0xF3F3F3,
		"Close Help     --> H");
}

void	ft_help(t_fractol *fractol)
{
	fractol->help = !fractol->help;
	if (fractol->help)
		help_drawer(fractol);
	else
		f_build(fractol);
}

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
		cnst.imagine = 2.0 * cnst.real * cnst.imagine - julia.imagine;
		cnst.real = x - y + julia.real;
		i++;
	}
	return (0);
}
