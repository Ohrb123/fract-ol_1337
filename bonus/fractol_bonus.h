/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:52:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/25 22:09:00 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	real;
	double	imagine;
}	t_complex;

typedef struct s_image
{
	void	*image;
	char	*pixels;
	int		bits;
	int		end;
	int		size_line;
}	t_image;

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_fractol
{
	void	*init;
	void	*window;
	t_image	image;
	char	*title;
	double	lost;
	int		iter;
	double	zoom;
	char	**av;
	int		ac;
	char	*error;
	char	*parse;
	double	right_left;
	double	up_down;
	int		color;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	arrow;
	int		y;
	int		x;
	t_bool	help;
	int		m_color;
}	t_fractol;

typedef struct s_atod
{
	double	res;
	double	frac;
	int		i;
	int		sign;
	char	*error;
	int		j;
	int		count;
}	t_atod;

# define HEIGHT 600
# define WIDTH 600

int			change_color(int i);
int			ft_strcmp(char *s1, char *s2);
void		f_init(t_fractol *fractol);
void		ft_error(void);
void		f_build(t_fractol *fractol);
int			ft_pixels(t_complex cnst, t_complex julia, t_fractol *fractol);
void		my_pixel_put(int x, int y, t_image *image, int color);
void		ft_events(t_fractol *fractol);
int			zoom(int key, int x, int y, t_fractol *fractol);
int			key_handle(int key, t_fractol *fractol);
int			ft_julia(t_complex cnst, t_complex julia, t_fractol *fractol);
double		ft_atod(char *str);
int			check_decimal(char *str, int i);
int			ft_parse(char *str);
void		julia_set(t_fractol *fractol, t_complex julia);
void		zoom_in(t_fractol *fractol, double x_axis, double y_axis);
int			f_exit(t_fractol *fractol);
void		data_init(t_fractol *fractol, int ac, char **av);
double		ft_abs(double n);
void		ft_help(t_fractol *fractol);
void		help_drawer(t_fractol *fractol);

#endif
