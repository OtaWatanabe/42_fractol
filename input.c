/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:53:47 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 09:23:53 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	print_instructions(void)
{
	ft_printf("mandelbrot\njulia_0\njulia_1\n");
}

void	process_input(int argc, char *argv[], t_vars *vars)
{
	if (argc == 1 || argc > 2)
	{
		print_instructions();
		exit(0);
	}
	else if (ft_memcmp(argv[1], "mandelbrot", 11) == 0)
		vars->type = "mandelbrot";
	else if (ft_memcmp(argv[1], "julia_0", 8) == 0)
		vars->type = "julia_0";
	else if (ft_memcmp(argv[1], "julia_1", 8) == 0)
		vars->type = "julia_1";
	else
	{
		print_instructions();
		exit(0);
	}
}
