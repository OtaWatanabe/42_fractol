/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:01:48 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:34:38 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	set_vars(t_vars *vars)
{
	int	i;

	vars->mlx = mlx_init();
	vars->img.img = mlx_new_image(vars->mlx, 1000, 500);
	vars->mlx_win = mlx_new_window(vars->mlx, 1000, 500, "fract-ol");
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	vars->loop = 100;
	mlx_hook(vars->mlx_win, 2, 0, handle_input, vars);
	mlx_hook(vars->mlx_win, 17, 0, handle_destroy, vars);
	mlx_hook(vars->mlx_win, 4, 0, handle_zoom, vars);
	i = 0;
	while (i < 1000)
	{
		vars->coordinate.x[i] = (i - 500) / 120.0;
		++i;
	}
	i = 0;
	while (i < 500)
	{
		vars->coordinate.y[i] = (i - 250) / 120.0;
		++i;
	}
}
