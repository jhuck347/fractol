/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:44:30 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:44:33 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_arrow_keys(int keycode, t_fractol *data)
{
	if (keycode == KEY_LEFT)
		data->offset_x -= 0.1 / data->zoom;
	else if (keycode == KEY_RIGHT)
		data->offset_x += 0.1 / data->zoom;
	else if (keycode == KEY_UP)
		data->offset_y -= 0.1 / data->zoom;
	else if (keycode == KEY_DOWN)
		data->offset_y += 0.1 / data->zoom;
	render_fractal(data);
}

void	handle_zoom_keys(int keycode, t_fractol *data)
{
	if (keycode == KEY_PLUS)
		data->zoom *= ZOOM_FACTOR;
	else if (keycode == KEY_MINUS)
		data->zoom /= ZOOM_FACTOR;
	render_fractal(data);
}

void	zoom(int button, int x, int y, t_fractol *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
	mouse_im = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	if (button == MOUSE_SCROLL_UP)
	{
		data->zoom *= ZOOM_FACTOR;
		data->offset_x = mouse_re - (x - WIDTH / 2.0) * 4.0 / WIDTH
			/ data->zoom;
		data->offset_y = mouse_im - (y - HEIGHT / 2.0) * 4.0 / HEIGHT
			/ data->zoom;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->zoom /= ZOOM_FACTOR;
		data->offset_x = mouse_re - (x - WIDTH / 2.0) * 4.0 / WIDTH
			/ data->zoom;
		data->offset_y = mouse_im - (y - HEIGHT / 2.0) * 4.0 / HEIGHT
			/ data->zoom;
	}
	render_fractal(data);
}
