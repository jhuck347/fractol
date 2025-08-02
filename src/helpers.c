/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:45:41 by juhuck            #+#    #+#             */
/*   Updated: 2025/08/02 12:57:20 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_help(void)
{
	ft_printf("Usage: ./fractol <fractal_type> [<parameters>]\n");
	ft_printf("Available fractal types:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia <kr> <ki> (e.g., julia -0.7 0.27015)\n");
	ft_printf("  burning_ship\n");
	ft_printf("Additional options:\n");
	ft_printf("  Use the mouse wheel to zoom in and out.\n");
	ft_printf("  Use arrow keys to move the view.\n");
	ft_printf("  Press 'Space' to change color schemes.\n");
	ft_printf("  Press 'ESC' to exit.\n");
}

int	is_valid_range(double value)
{
	return (value >= -1.0 && value <= 1.0);
}

int	validate_fractal_type(char *arg)
{
	if (ft_strncmp(arg, MANDELBROT_STR, ft_strlen(MANDELBROT_STR) + 1) == 0)
		return (1);
	if (ft_strncmp(arg, JULIA_STR, ft_strlen(JULIA_STR) + 1) == 0)
		return (1);
	if (ft_strncmp(arg, BURNING_SHIP_STR, ft_strlen(BURNING_SHIP_STR) + 1) == 0)
		return (1);
	return (0);
}

int	handle_julia(int argc, char **argv, t_fractol *data)
{
	if (argc != 4)
		return (handle_invalid_arguments());
	data->fractal_type = JULIA;
	data->kr = parse_float(argv[2]);
	data->ki = parse_float(argv[3]);
	if (!is_valid_range(data->kr) || !is_valid_range(data->ki))
	{
		ft_printf("Error: Julia parameters must be between -1.0 and 1.0\n");
		return (handle_invalid_arguments());
	}
	return (1);
}
