/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:04:19 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:24:14 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fractol");
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars)
{
	if (vars->type[0] == 'm')
		mandelbrot(vars);
	else
		julia(vars);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		return (0);
	process_input(argc, argv, vars);
	set_vars(vars);
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	mlx_loop(vars->mlx);
	free(vars);
}
