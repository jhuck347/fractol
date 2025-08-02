/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:44:37 by jhuck             #+#    #+#             */
/*   Updated: 2025/07/30 17:25:52 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mlx(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!data->win)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		exit(EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

static void	init_fractal(t_fractol *data)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
}

void	init_color_palettes(t_color palettes[NUM_PALETTES][MAX_ITERATIONS])
{
	init_palette_one(palettes[0]);
	init_palette_two(palettes[1]);
	init_palette_three(palettes[2]);
	init_palette_four(palettes[3]);
	init_palette_five(palettes[4]);
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (!parse_arguments(argc, argv, &data))
		return (1);
	init_color_palettes(data.palettes);
	data.selected_palette = data.palettes[0];
	init_mlx(&data);
	init_fractal(&data);
	render_fractal(&data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_mouse_hook(data.win, mouse_event, &data);
	mlx_hook(data.win, CLOSE_EVENT, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
