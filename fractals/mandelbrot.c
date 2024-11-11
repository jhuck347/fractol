/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:42:28 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:42:31 by jhuck            ###   ########.fr       */
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
	if (n == MAX_ITERATIONS)
		return (MAX_ITERATIONS);
	return (n);
}
