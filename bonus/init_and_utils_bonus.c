/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:02:49 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:30 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	f_init(t_fractol *fractol)
{
	fractol->init = mlx_init();
	if (!fractol->init)
		ft_error();
	fractol->window = mlx_new_window \
	(fractol->init, HEIGHT, WIDTH, fractol->title);
	if (!fractol->window)
	{
		free (fractol->init);
		ft_error();
	}
	fractol->image.image = mlx_new_image(fractol->init, HEIGHT, WIDTH);
	if (!fractol->image.image)
	{
		mlx_destroy_window(fractol->init, fractol->window);
		free (fractol->init);
		ft_error();
	}
	fractol->image.pixels = mlx_get_data_addr(fractol->image.image, \
	&fractol->image.bits, &fractol->image.size_line, &fractol->image.end);
	ft_events(fractol);
}

void	ft_error(void)
{
	perror("Allocation problem!\n");
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	f_exit(t_fractol *fractol)
{
	write(1, "Good bye!\n", 10);
	mlx_destroy_window(fractol->init, fractol->window);
	exit(0);
}

double	ft_abs(double n)
{
	if (n < 0.0)
		return (n *= -1);
	return (n);
}
