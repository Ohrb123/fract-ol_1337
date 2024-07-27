/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:52:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 22:09:29 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_color(int i)
{
	int	red;
	int	green;
	int	blue;

	red = (i * 11) % 256;
	green = (i * 5) % 256;
	blue = (i * 13) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	i;

	i = (y * image->size_line) + (x * (image->bits / 8));
	*(unsigned int *)(image->pixels + i) = color;
}

int	ft_pixels(t_complex cnst, t_complex julia, t_fractol *fractol)
{
	t_complex	z;
	int			i;
	double		x;
	double		y;

	z.real = 0;
	z.imagine = 0;
	i = 0;
	while (i < fractol->iter)
	{
		x = z.real * z.real;
		y = z.imagine * z.imagine;
		if (x + y > 4)
			return (change_color(i * 0.5));
		else if (!ft_strcmp(fractol->av[1], "julia"))
			return (change_color(ft_julia(cnst, julia, fractol)));
		else
			z.imagine = 2 * z.imagine * z.real + cnst.imagine;
		z.real = x - y + cnst.real;
		i++;
	}
	return (change_color(0));
}

void	mlx_while(t_fractol *fractol, t_complex julia)
{
	int			color;
	t_complex	z;

	fractol->y = -1;
	while (++fractol->y < WIDTH)
	{
		fractol->y = -1;
		while (++fractol->y < WIDTH)
		{
			fractol->x = -1;
			while (++fractol->x < HEIGHT)
			{
				z.real = (fractol->x - WIDTH / 2.0) \
				* 4.0 / WIDTH * fractol->zoom;
				z.imagine = (fractol->y - HEIGHT / 2.0) * 4.0 \
				/ HEIGHT * fractol->zoom;
				color = ft_pixels(z, julia, fractol);
				my_pixel_put(fractol->x, fractol->y, &fractol->image, color);
			}
		}
	}
}

void	f_build(t_fractol *fractol)
{
	t_complex	julia;

	julia.imagine = 0.0;
	julia.real = 0.0;
	if (fractol->ac > 2)
	{
		julia.real = ft_atod(fractol->av[2]);
		julia.imagine = ft_atod(fractol->av[3]);
	}
	mlx_while(fractol, julia);
	mlx_clear_window(fractol->init, fractol->window);
	mlx_put_image_to_window \
	(fractol->init, fractol->window, fractol->image.image, 0, 0);
}
