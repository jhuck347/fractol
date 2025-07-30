#include "../includes/fractol.h"
#include <pthread.h>

#define THREADS 8

typedef struct s_thread_data
{
	t_fractol	*data;
	int			start_y;
	int			end_y;
	double		scale_r;
	double		scale_i;
}	t_thread_data;

static void	convert_pixel_to_complex(int x, int y, t_fractol *data,
		t_complex *c, double scale_r, double scale_i)
{
	c->re = data->min_r + (x * scale_r);
	c->im = data->max_i - (y * scale_i);
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

static void	render_pixel(int x, int y, t_fractol *data,
		double scale_r, double scale_i)
{
	t_complex	c;
	int			color;

	convert_pixel_to_complex(x, y, data, &c, scale_r, scale_i);
	color = get_fractal_color(data, c);
	put_pixel_to_image(data, x, y, color);
}

static void	*render_section(void *arg)
{
	t_thread_data	*t;
	int				x;
	int				y;

	t = (t_thread_data *)arg;
	y = t->start_y;
	while (y < t->end_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(x, y, t->data, t->scale_r, t->scale_i);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	render_fractal(t_fractol *data)
{
	pthread_t		threads[THREADS];
	t_thread_data	thread_data[THREADS];
	double			scale_r;
	double			scale_i;
	int				i;

	scale_r = (data->max_r - data->min_r) / WIDTH;
	scale_i = (data->max_i - data->min_i) / HEIGHT;
	i = 0;
	while (i < THREADS)
	{
		thread_data[i].data = data;
		thread_data[i].start_y = i * (HEIGHT / THREADS);
		thread_data[i].end_y = (i + 1) * (HEIGHT / THREADS);
		thread_data[i].scale_r = scale_r;
		thread_data[i].scale_i = scale_i;
		pthread_create(&threads[i], NULL, render_section, &thread_data[i]);
		i++;
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
