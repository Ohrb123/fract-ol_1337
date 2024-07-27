/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:42:21 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:12 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
			return (change_color(i * 0.6) + fractol->color);
		if (!ft_strcmp(fractol->av[1], "ship"))
			z.imagine = ft_abs(2.0 * z.real * z.imagine) + cnst.imagine;
		else if (!ft_strcmp(fractol->av[1], "julia"))
			return (change_color(ft_julia(cnst, julia, fractol)) \
	+ fractol->color);
		else
			z.imagine = 2.0 * z.imagine * z.real + cnst.imagine;
		z.real = x - y + cnst.real;
		i++;
	}
	return (change_color(0));
}

void	ft_mlx(t_fractol *fractol)
{
	mlx_clear_window(fractol->init, fractol->window);
	mlx_put_image_to_window(fractol->init, fractol->window, \
	fractol->image.image, 0, 0);
	mlx_string_put(fractol->init, fractol->window, 20, 10, 0xF3F3F3,
		"Help --> H");
}

void	mlx_while(t_fractol *fractol, t_complex julia)
{
	t_complex	z;

	fractol->y = -1;
	while (++fractol->y < WIDTH)
	{
		fractol->x = -1;
		while (++fractol->x < HEIGHT)
		{
			z.real = fractol->x_min + fractol->x * \
			(fractol->x_max - fractol->x_min) / WIDTH + fractol->right_left;
			z.imagine = (fractol->y_min + fractol->y * \
			(fractol->y_max - fractol->y_min) / HEIGHT) + fractol->up_down;
			fractol->m_color = ft_pixels(z, julia, fractol);
			my_pixel_put(fractol->x, fractol->y, \
			&fractol->image, fractol->m_color);
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
	ft_mlx(fractol);
}
