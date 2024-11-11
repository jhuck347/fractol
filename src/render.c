/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:45:17 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:45:20 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	convert_pixel_to_complex(int x, int y, t_fractol *data,
		t_complex *c)
{
	c->re = data->min_r + (x * (data->max_r - data->min_r) / WIDTH);
	c->im = data->max_i - (y * (data->max_i - data->min_i) / HEIGHT);
}

int	get_fractal_color(t_fractol *data, t_complex c)
{
	int	iteration;

	if (data->fractal_type == MANDELBROT)
		iteration = mandelbrot(c.re, c.im);
	else if (data->fractal_type == JULIA)
		iteration = julia(data, c.re, c.im);
	else if (data->fractal_type == BURNING_SHIP)
		iteration = burning_ship(c.re, c.im);
	else
		return (0x000000);
	return (get_color_from_palette(iteration, data->selected_palette,
			data->color));
}

static void	render_pixel(int x, int y, t_fractol *data)
{
	t_complex	c;
	int			color;

	convert_pixel_to_complex(x, y, data, &c);
	color = get_fractal_color(data, c);
	put_pixel_to_image(data, x, y, color);
}

void	render_fractal(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
