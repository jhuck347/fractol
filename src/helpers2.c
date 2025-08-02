/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:49:04 by juhuck            #+#    #+#             */
/*   Updated: 2025/08/02 12:49:34 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	handle_non_julia(int argc, char *arg, t_fractol *data)
{
	if (ft_strncmp(arg, MANDELBROT_STR,
			ft_strlen(MANDELBROT_STR) + 1) == 0)
	{
		if (argc != 2)
			return (handle_invalid_arguments());
		data->fractal_type = MANDELBROT;
	}
	else if (ft_strncmp(arg, BURNING_SHIP_STR,
			ft_strlen(BURNING_SHIP_STR) + 1) == 0)
	{
		if (argc != 2)
			return (handle_invalid_arguments());
		data->fractal_type = BURNING_SHIP;
	}
	else
		return (handle_invalid_arguments());
	return (1);
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
	if (ft_strncmp(argv[1], JULIA_STR, ft_strlen(JULIA_STR) + 1) == 0)
		return (handle_julia(argc, argv, data));
	return (handle_non_julia(argc, argv[1], data));
}
