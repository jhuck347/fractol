/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:44:00 by jhuck             #+#    #+#             */
/*   Updated: 2025/07/30 10:08:12 by marvin           ###   ########.fr       */
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
	ft_printf("  Press 'C' to change color schemes.\n");
	ft_printf("  Press 'ESC' to exit.\n");
}

int	validate_fractal_type(char *arg)
{
	if (ft_strncmp(arg, MANDELBROT_STR, ft_strlen(MANDELBROT_STR)) == 0)
		return (1);
	if (ft_strncmp(arg, JULIA_STR, ft_strlen(JULIA_STR)) == 0)
		return (1);
	if (ft_strncmp(arg, BURNING_SHIP_STR, ft_strlen(BURNING_SHIP_STR)) == 0)
		return (1);
	return (0);
}

int	handle_invalid_arguments(void)
{
	display_help();
	return (0);
}

int	parse_arguments(int argc, char **argv, t_fractol *data)
{
	if (argc < 2)
		return (handle_invalid_arguments());
	if (!validate_fractal_type(argv[1]))
		return (handle_invalid_arguments());
	if (ft_strncmp(argv[1], JULIA_STR, ft_strlen(JULIA_STR)) == 0 && argc == 4)
	{
		data->fractal_type = JULIA;
		data->kr = parse_float(argv[2]);
		data->ki = parse_float(argv[3]);
	}
	else if (ft_strncmp(argv[1], MANDELBROT_STR, ft_strlen(MANDELBROT_STR)) == 0)
	{
		data->fractal_type = MANDELBROT;
	}
	else if (ft_strncmp(argv[1], BURNING_SHIP_STR, ft_strlen(BURNING_SHIP_STR)) == 0)
	{
		data->fractal_type = BURNING_SHIP;
	}
	else
		return (handle_invalid_arguments());
	return (1);
}
