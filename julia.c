/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:24:26 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:35:02 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	julia_divergence(double x, double y, t_vars *vars)
{
	double	zx;
	double	zy;
	double	c;
	int		i;

	zx = 0.4;
	zy = -0.325;
	i = 0;
	if (vars->type[6] == '1')
	{
		zx = -0.8;
		zy = 0.156;
	}
	while (i < vars->loop)
	{
		if (x * x + y * y > 4)
			return (i);
		c = x * x - y * y + zx;
		y = 2 * x * y + zy;
		x = c;
		++i;
	}
	return (i);
}

void	julia_map_color(t_vars *vars, int color, int x, int y)
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
	else
		my_mlx_pixel_put(&vars->img, x, y, large_color(color));
}

void	julia(t_vars *vars)
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
			color = julia_divergence(vars->coordinate.x[j],
					vars->coordinate.y[i], vars);
			julia_map_color(vars, color, j, i);
			++j;
		}
		++i;
	}
}
