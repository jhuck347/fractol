/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:42:52 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:42:55 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "constants.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_palette_config
{
	int		r_multiplier;
	int		g_multiplier;
	int		b_multiplier;
	int		r_offset;
	int		g_offset;
	int		b_offset;
}			t_palette_config;
typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		fractal_type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	t_color	palettes[NUM_PALETTES][MAX_ITERATIONS];
	t_color	*selected_palette;
}			t_fractol;

void		render_fractal(t_fractol *data);
int			key_event(int keycode, t_fractol *mlx);
int			mouse_event(int keycode, int x, int y, t_fractol *data);
int			close_window(t_fractol *data);
void		handle_arrow_keys(int keycode, t_fractol *data);
void		handle_zoom_keys(int keycode, t_fractol *data);
void		put_pixel_to_image(t_fractol *data, int x, int y, int color);
int			get_color(int iteration);
void		color_shift(t_fractol *data);
int			parse_arguments(int argc, char **argv, t_fractol *data);
double		parse_float(char *str);
int			mandelbrot(double cr, double ci);
int			julia_shift(int x, int y, t_fractol *data);
int			julia(t_fractol *data, double zr, double zi);
int			burning_ship(double cr, double ci);
int			get_color_from_palette(int iteration, t_color *palette,
				int color_shift);
int			parse_color_hex(char *color);
void		init_palette_one(t_color *palette);
void		init_palette_two(t_color *palette);
void		init_palette_three(t_color *palette);
void		init_palette_four(t_color *palette);
void		init_palette_five(t_color *palette);

#endif
