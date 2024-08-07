/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:05:22 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/08/07 08:21:00 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "mlx/mlx.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

# define BK_ESCAPE 53

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cooridanate
{
	double	x[1000];
	double	y[500];
}	t_coordinate;

typedef struct s_vars
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	t_coordinate	coordinate;
	int				loop;
	char			*type;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_vars *vars);
void	julia(t_vars *vars);
void	map_color(t_vars *vars, int color, int x, int y);
int		get_color(int t, int r, int g, int b);
void	set_vars(t_vars *vars);
int		handle_input(int keysym, t_vars *vars);
int		handle_destroy(t_vars *vars);
int		handle_zoom(int button, int x, int y, t_vars *vars);
void	zoom(t_vars *vars, double mag, int x, int y);
void	process_input(int argc, char *argv[], t_vars *vars);
int		large_color(int color);
void	draw(t_vars *vars);
int		mandel_divergence(double x, double y, int loop);
int		julia_divergence(double x, double y, t_vars *vars);
int		calculate_color(t_vars *vars, double x, double y);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	slide_right(t_vars *vars);
void	slide_left(t_vars *vars);
void	slide_up(t_vars *vars);
void	slide_down(t_vars *vars);

#endif