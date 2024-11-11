/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:43:32 by jhuck             #+#    #+#             */
/*   Updated: 2024/10/15 04:43:40 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color_from_palette(int iteration, t_color *palette, int color_shift)
{
	t_color	color;
	int		color_value;

	if (iteration == MAX_ITERATIONS)
		return (COLOR_BLACK);
	color = palette[(iteration + color_shift) % MAX_ITERATIONS];
	color_value = (color.r << 16) | (color.g << 8) | color.b;
	return (color_value);
}
