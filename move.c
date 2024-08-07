/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:13 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:27:16 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calculate_color(t_vars *vars, double x, double y)
{
	if (vars->type[0] == 'm')
		return (mandel_divergence(x, y, vars->loop));
	return (julia_divergence(x, y, vars));
}

void	move_right(t_vars *vars)
{
	int		x;
	int		y;
	int		color;

	slide_right(vars);
	x = 995;
	while (x < 1000)
	{
		y = 0;
		while (y < 500)
		{
			color = calculate_color(vars,
					vars->coordinate.x[x], vars->coordinate.y[y]);
			map_color(vars, color, x, y);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}

void	move_left(t_vars *vars)
{
	int		x;
	int		y;
	int		color;

	slide_left(vars);
	x = 0;
	while (x < 5)
	{
		y = 0;
		while (y < 500)
		{
			color = calculate_color(vars,
					vars->coordinate.x[x], vars->coordinate.y[y]);
			map_color(vars, color, x, y);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}

void	move_down(t_vars *vars)
{
	int		x;
	int		y;
	int		color;

	slide_down(vars);
	x = 0;
	while (x < 1000)
	{
		y = 495;
		while (y < 500)
		{
			color = calculate_color(vars,
					vars->coordinate.x[x], vars->coordinate.y[y]);
			map_color(vars, color, x, y);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}

void	move_up(t_vars *vars)
{
	int		x;
	int		y;
	int		color;

	slide_up(vars);
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 5)
		{
			color = calculate_color(vars,
					vars->coordinate.x[x], vars->coordinate.y[y]);
			map_color(vars, color, x, y);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}
