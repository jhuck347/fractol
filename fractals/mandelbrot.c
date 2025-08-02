/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:21:20 by juhuck            #+#    #+#             */
/*   Updated: 2025/07/30 17:26:39 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	zr_squared;
	double	zi_squared;

	zr = 0.0;
	zi = 0.0;
	zr_squared = 0.0;
	zi_squared = 0.0;
	n = 0;
	while (zr_squared + zi_squared <= 4.0 && n < MAX_ITERATIONS)
	{
		zi = 2.0 * zr * zi + ci;
		zr = zr_squared - zi_squared + cr;
		zr_squared = zr * zr;
		zi_squared = zi * zi;
		n++;
	}
	return (n);
}
