/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:48:03 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:34:21 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	slide_right(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < 1000)
	{
		if (x < 995)
		{
			vars->coordinate.x[x] = vars->coordinate.x[x + 5];
			y = 0;
			while (y < 500)
			{
				color = *(int *)(vars->img.addr + (y * vars->img.line_length
							+ (x + 5) * (vars->img.bits_per_pixel / 8)));
				my_mlx_pixel_put(&vars->img, x, y, color);
				++y;
			}
		}
		else
			vars->coordinate.x[x] = 2 * 
				vars->coordinate.x[x - 1] - vars->coordinate.x[x - 2];
		++x;
	}
}

void	slide_left(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	x = 999;
	while (0 <= x)
	{
		if (5 <= x)
		{
			vars->coordinate.x[x] = vars->coordinate.x[x - 5];
			y = 0;
			while (y < 500)
			{
				color = *(int *)(vars->img.addr + (y * vars->img.line_length
							+ (x - 5) * (vars->img.bits_per_pixel / 8)));
				my_mlx_pixel_put(&vars->img, x, y, color);
				++y;
			}
		}
		else
			vars->coordinate.x[x] = 2
				* vars->coordinate.x[x + 1] - vars->coordinate.x[x + 2];
		--x;
	}
}

void	slide_down(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 500)
	{
		if (y < 495)
		{
			vars->coordinate.y[y] = vars->coordinate.y[y + 5];
			x = 0;
			while (x < 1000)
			{
				color = *(int *)(vars->img.addr 
						+ ((y + 5) * vars->img.line_length 
							+ x * (vars->img.bits_per_pixel / 8)));
				my_mlx_pixel_put(&vars->img, x, y, color);
				++x;
			}
		}
		else
			vars->coordinate.y[y] = 2
				* vars->coordinate.y[y - 1] - vars->coordinate.y[y - 2];
		++y;
	}
}

void	slide_up(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	y = 499;
	while (0 <= y)
	{
		if (5 <= y)
		{
			vars->coordinate.y[y] = vars->coordinate.y[y - 5];
			x = 0;
			while (x < 1000)
			{
				color = *(int *)(vars->img.addr
						+ ((y - 5) * vars->img.line_length
							+ x * (vars->img.bits_per_pixel / 8)));
				my_mlx_pixel_put(&vars->img, x, y, color);
				++x;
			}
		}
		else
			vars->coordinate.y[y] = 2
				* vars->coordinate.y[y + 1] - vars->coordinate.y[y + 2];
		--y;
	}
}
