/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:51 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 08:24:47 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	handle_input(int keysym, t_vars *vars)
{
	if (keysym == BK_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	else if (keysym == 124)
		move_right(vars);
	else if (keysym == 123)
		move_left(vars);
	else if (keysym == 126)
		move_up(vars);
	else if (keysym == 125)
		move_down(vars);
	return (0);
}

int	handle_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

void	zoom(t_vars *vars, double mag, int x, int y)
{
	int		i;
	double	cx;
	double	cy;

	cx = vars->coordinate.x[x];
	cy = vars->coordinate.y[y];
	i = 0;
	while (i < 1000)
	{
		vars->coordinate.x[i] = cx + (vars->coordinate.x[i] - cx) * mag;
		++i;
	}
	i = 0;
	while (i < 500)
	{
		vars->coordinate.y[i] = cy + (vars->coordinate.y[i] - cy) * mag;
		++i;
	}
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}

int	handle_zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		--vars->loop;
		zoom(vars, 1.1, x, y);
	}
	else if (button == 5)
	{
		++vars->loop;
		zoom(vars, 1 / 1.1, x, y);
	}
	return (0);
}
