/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:47:54 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:47:54 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_color(int t, int color)
{
	int r;
	int g;
	int b;

	r = get_red_color(color);
	g = get_green_color(color);
	b = get_blue_color(color);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_color(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_red_color(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_blue_color(int color)
{
	return ((color) & 0xFF);
}

int	get_green_color(int color)
{
	return ((color >> 8) & 0xFF);
}
