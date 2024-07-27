/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:51:18 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:31 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*string_norm(void)
{
	return ("This julia is ceated to show you the beauty of \
julia soo to see it use the values within this range <= 2 && >= -2\n");
}

static int	check_sign(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	return (sign);
}

double	ft_atod(char *str)
{
	t_atod	var;

	var.res = 0.0;
	var.frac = 0.1;
	var.sign = 1;
	var.i = 0;
	var.error = string_norm();
	if (str[var.i] == '-' || str[var.i] == '+')
	{
		var.sign = check_sign(str);
		var.i++;
	}
	while (str[var.i] >= '0' && str[var.i] <= '9')
		var.res = var.res * 10.0 + (str[var.i++] - '0');
	if (str[var.i++] == '.')
	{
		while (str[var.i] >= '0' && str[var.i] <= '9')
		{
			var.res += (str[var.i++] - '0') * var.frac;
			var.frac /= 10.0;
		}
	}
	if (var.sign * var.res > 2.0 || var.sign * var.res < -2.0)
		(write(2, var.error, 114), exit(1));
	return (var.sign * var.res);
}

int	ft_parse(char *str)
{
	t_atod	var;

	var.j = 0;
	var.count = 0;
	while (str[var.j] == ' ' || str[var.j] == '\t')
		var.j++;
	if (str[var.j] == '-' || str[var.j] == '+')
		var.j++;
	if (str[var.j] == '.')
		return (0);
	while ((str[var.j] >= '0' && str[var.j] <= '9') || str[var.j] == '.')
	{
		if (str[var.j] == '.')
			var.count++;
		else if (str[var.j] != '.' && !str[var.j + 1] && var.count <= 1)
			return (1);
		var.j++;
	}
	return (0);
}
