/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:21:25 by juhuck            #+#    #+#             */
/*   Updated: 2025/08/02 12:57:36 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// ───── External Headers ───────────────────────────
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

// ───── Internal Headers ───────────────────────────
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "constants.h"

// ───── Struct Definitions ─────────────────────────

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

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
}	t_fractol;

// ───── Rendering ──────────────────────────────────

void		render_fractal(t_fractol *data);
void		put_pixel_to_image(t_fractol *data, int x, int y, int color);

// ───── Event Handling ─────────────────────────────

int			key_event(int keycode, t_fractol *data);
int			mouse_event(int button, int x, int y, t_fractol *data);
int			close_window(t_fractol *data);
void		handle_arrow_keys(int keycode, t_fractol *data);
void		handle_zoom_keys(int keycode, t_fractol *data);

// ───── Color & Palette ────────────────────────────

void		color_shift(t_fractol *data);
int			get_color(int iteration);
int			get_color_from_palette(int iteration, t_color *palette, int shift);

void		init_palette_one(t_color *palette);
void		init_palette_two(t_color *palette);
void		init_palette_three(t_color *palette);
void		init_palette_four(t_color *palette);
void		init_palette_five(t_color *palette);

// ───── Argument Parsing ───────────────────────────

int			parse_arguments(int argc, char **argv, t_fractol *data);
int			parse_color_hex(char *color);
double		parse_float(char *str);
void		display_help(void);
int			is_valid_range(double value);
int			validate_fractal_type(char *arg);
int			handle_invalid_arguments(void);
int			parse_arguments(int argc, char **argv, t_fractol *data);
int			handle_julia(int argc, char **argv, t_fractol *data);

// ───── Fractal Algorithms ─────────────────────────

int			mandelbrot(double cr, double ci);
int			julia(t_fractol *data, double zr, double zi);
int			julia_shift(int x, int y, t_fractol *data);
int			burning_ship(double cr, double ci);

#endif
