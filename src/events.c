/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:43:54 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:43:57 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(t_fractol *data, double zoom)
{
	double	center_r;
	double	center_i;
	double	range_r;
	double	range_i;

	range_r = data->max_r - data->min_r;
	range_i = data->max_i - data->min_i;
	center_r = data->min_r + range_r / 2;
	center_i = data->min_i + range_i / 2;
	range_r *= zoom;
	range_i *= zoom;
	data->min_r = center_r - range_r / 2;
	data->max_r = center_r + range_r / 2;
	data->min_i = center_i - range_i / 2;
	data->max_i = center_i + range_i / 2;
}

static void	move(t_fractol *data, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = data->max_r - data->min_r;
	center_i = data->max_i - data->min_i;
	if (direction == 'R')
	{
		data->min_r += center_r * distance;
		data->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		data->min_r -= center_r * distance;
		data->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		data->min_i -= center_i * distance;
		data->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		data->min_i += center_i * distance;
		data->max_i += center_i * distance;
	}
}

int	key_event(int keycode, t_fractol *data)
{
	if (keycode == KEY_ESC)
		return (close_window(data), 0);
	else if (keycode == KEY_PLUS)
		zoom(data, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(data, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(data, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(data, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(data, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(data, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(data);
	else
		return (1);
	render_fractal(data);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *data)
{
	if (keycode == MOUSE_SCROLL_UP)
	{
		zoom(data, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(data, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(data, (double)x / WIDTH, 'R');
		if (y < 0)
			move(data, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(data, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_SCROLL_DOWN)
		zoom(data, 2);
	else if (keycode == MOUSE_CLICK)
	{
		if (data->fractal_type == JULIA)
			julia_shift(x, y, data);
	}
	else
		return (0);
	render_fractal(data);
	return (0);
}
