/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:42:13 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:42:17 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITERATIONS)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(tmp);
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		n++;
	}
	return (n);
}
