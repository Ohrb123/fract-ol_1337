/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:41 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/20 22:03:36 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handle(int key, t_fractol *fractol)
{
	if (key == 53)
		f_exit(fractol);
	if (key == 69 && fractol->iter <= 200)
		fractol->iter += 20;
	if (key == 78 && fractol->iter > 40)
		fractol->iter -= 20;
	if (key == 53 || key == 69 || key == 78)
		f_build(fractol);
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (key == 4)
		fractol->zoom *= 0.95;
	if (key == 5)
		fractol->zoom *= 1.05;
	if (key == 5 || key == 4)
		f_build (fractol);
	return (0);
}

void	ft_events(t_fractol *fractol)
{
	mlx_mouse_hook (fractol->window, zoom, fractol);
	mlx_hook(fractol->window, 02, 0, key_handle, fractol);
	mlx_hook(fractol->window, 17, 0, f_exit, fractol);
}
