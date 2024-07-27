/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:41 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:26 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_keys(int key, t_fractol *fractol)
{
	if (key == 53)
		f_exit(fractol);
	if (key == 4)
		ft_help(fractol);
	if (key == 49)
	{
		data_init(fractol, 0, NULL);
		f_build(fractol);
	}
	if (key == 124)
		fractol->right_left += 0.05 * fractol->arrow;
	if (key == 123)
		fractol->right_left -= 0.05 * fractol->arrow;
	if (key == 125)
		fractol->up_down += 0.05 * fractol->arrow;
	if (key == 126)
		fractol->up_down -= 0.05 * fractol->arrow;
	if (key == 48)
		fractol->color += 1000;
	if (key == 50)
		fractol->color -= 1000;
	if (key == 69 && fractol->iter <= 500)
		fractol->iter += 20;
	if (key == 78 && fractol->iter > 40)
		fractol->iter -= 20;
}

int	key_handle(int key, t_fractol *fractol)
{
	ft_keys(key, fractol);
	if (key == 124 || key == 123 || key == 125 || key == 126 \
	|| key == 69 || key == 78 || key == 48 || key == 50)
		f_build(fractol);
	return (0);
}

void	zoom_in(t_fractol *fractol, double x_axis, double y_axis)
{
	fractol->x_min = x_axis + fractol->zoom * (fractol->x_min - x_axis);
	fractol->x_max = x_axis + fractol->zoom * (fractol->x_max - x_axis);
	fractol->y_min = y_axis + fractol->zoom * (fractol->y_min - y_axis);
	fractol->y_max = y_axis + fractol->zoom * (fractol->y_max - y_axis);
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	double	x_axis;
	double	y_axis;

	if (x >= 0 && y >= 0 && (key == 4 || key == 5))
	{
		x_axis = fractol->x_min + x * \
		((fractol->x_max - fractol->x_min) / WIDTH);
		y_axis = fractol->y_min + y * \
		((fractol->y_max - fractol->y_min) / HEIGHT);
		if (key == 4)
		{
			fractol->zoom = 0.89;
			fractol->arrow *= 0.89;
		}
		else if (key == 5)
		{
			fractol->zoom = 1.07;
			fractol->arrow *= 1.07;
		}
		zoom_in(fractol, x_axis, y_axis);
		f_build (fractol);
	}
	return (0);
}

void	ft_events(t_fractol *fractol)
{
	mlx_mouse_hook (fractol->window, zoom, fractol);
	mlx_hook(fractol->window, 02, 0, key_handle, fractol);
	mlx_hook(fractol->window, 17, 0, f_exit, fractol);
}
