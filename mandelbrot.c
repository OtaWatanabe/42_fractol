/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:54:32 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:35:15 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	mandel_divergence(double x, double y, int loop)
{
	double	zx;
	double	zy;
	double	c;
	int		i;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < loop)
	{
		c = zx * zx - zy * zy + x;
		zy = 2 * zx * zy + y;
		zx = c;
		if (zx * zx + zy * zy > 4)
			return (i);
		++i;
	}
	return (i);
}

int	large_color(int color)
{
	color %= 96;
	if (color < 32)
		return (get_color(0, 255, 255 - 8 * color, 8 * color));
	if (color < 64)
		return (get_color(0, 512 - 8 * color, 8 * color - 256, 255));
	return (get_color(0, 8 * color - 512, 255, 768 - color * 8));
}

void	map_color(t_vars *vars, int color, int x, int y)
{
	if (color == vars->loop)
		my_mlx_pixel_put(&vars->img, x, y, 0);
	else if (color < 32)
		my_mlx_pixel_put(&vars->img, x, y, get_color(0, 0, 0, 8 * color));
	else if (color < 64)
		my_mlx_pixel_put(&vars->img, x, y,
			get_color(0, 511 - 8 * color, 8 * color - 256, 255));
	else if (color < 96)
		my_mlx_pixel_put(&vars->img, x, y,
			get_color(0, 8 * color - 512, 255, 767 - color * 8));
	else if (color < vars->loop)
		my_mlx_pixel_put(&vars->img, x, y, large_color(color));
}

void	mandelbrot(t_vars *vars)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 1000)
		{
			color = mandel_divergence(vars->coordinate.x[j],
					vars->coordinate.y[i], vars->loop);
			map_color(vars, color, j, i);
			++j;
		}
		++i;
	}
}
