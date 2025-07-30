#include "../includes/fractol.h"

void	put_pixel_to_image(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iteration)
{
	if (iteration < MAX_ITERATIONS)
		return ((iteration * 0xFF / MAX_ITERATIONS) << 16);
	return (COLOR_BLACK);
}

void	color_shift(t_fractol *data)
{
	static int	i = 0;

	i = (i + 1) % 3;
	if (i == 0)
		data->color = 0xFF;
	else if (i == 1)
		data->color = 0xFF00;
	else
		data->color = 0xFABADA;
}

int	close_window(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
