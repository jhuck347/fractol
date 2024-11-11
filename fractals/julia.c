/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:42:21 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:42:24 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_shift(int x, int y, t_fractol *data)
{
	data->kr = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
	data->ki = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	render_fractal(data);
	return (0);
}

int	julia(t_fractol *data, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->ki;
		zr = zr * zr - zi * zi + data->kr;
		zi = tmp;
		n++;
	}
	return (n);
}
