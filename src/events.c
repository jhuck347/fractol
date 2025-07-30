#include "../includes/fractol.h"

static void	zoom(t_fractol *data, double zoom)
{
	double	center_r = data->min_r + (data->max_r - data->min_r) / 2;
	double	center_i = data->min_i + (data->max_i - data->min_i) / 2;
	double	range_r = (data->max_r - data->min_r) * zoom;
	double	range_i = (data->max_i - data->min_i) * zoom;

	data->min_r = center_r - range_r / 2;
	data->max_r = center_r + range_r / 2;
	data->min_i = center_i - range_i / 2;
	data->max_i = center_i + range_i / 2;
}

static void	move(t_fractol *data, double distance, char dir)
{
	double	range_r = data->max_r - data->min_r;
	double	range_i = data->max_i - data->min_i;

	if (dir == 'R')
		data->min_r += range_r * distance, data->max_r += range_r * distance;
	else if (dir == 'L')
		data->min_r -= range_r * distance, data->max_r -= range_r * distance;
	else if (dir == 'U')
		data->min_i += range_i * distance, data->max_i += range_i * distance;
	else if (dir == 'D')
		data->min_i -= range_i * distance, data->max_i -= range_i * distance;
}

static void	handle_mouse_zoom(t_fractol *data, int x, int y)
{
	int		dx = x - WIDTH / 2;
	int		dy = y - HEIGHT / 2;

	zoom(data, 0.5);
	if (dx < 0)
		move(data, (double)(-dx) / WIDTH, 'L');
	else if (dx > 0)
		move(data, (double)dx / WIDTH, 'R');
	if (dy < 0)
		move(data, (double)(-dy) / HEIGHT, 'U');
	else if (dy > 0)
		move(data, (double)dy / HEIGHT, 'D');
}

int	mouse_event(int key, int x, int y, t_fractol *data)
{
	if (key == MOUSE_SCROLL_UP)
		handle_mouse_zoom(data, x, y);
	else if (key == MOUSE_SCROLL_DOWN)
		zoom(data, 2);
	else if (key == MOUSE_CLICK && data->fractal_type == JULIA)
		julia_shift(x, y, data);
	else
		return (0);
	render_fractal(data);
	return (0);
}

int	key_event(int key, t_fractol *data)
{
	if (key == KEY_ESC)
		return (close_window(data), 0);
	else if (key == KEY_PLUS)
		zoom(data, 0.5);
	else if (key == KEY_MINUS)
		zoom(data, 2);
	else if (key == KEY_UP || key == KEY_W)
		move(data, 0.2, 'U');
	else if (key == KEY_DOWN || key == KEY_S)
		move(data, 0.2, 'D');
	else if (key == KEY_LEFT || key == KEY_A)
		move(data, 0.2, 'L');
	else if (key == KEY_RIGHT || key == KEY_D)
		move(data, 0.2, 'R');
	else if (key == KEY_SPACE)
		color_shift(data);
	else
		return (1);
	render_fractal(data);
	return (0);
}
