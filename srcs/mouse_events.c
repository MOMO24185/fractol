/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:38:11 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 13:38:11 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	scroll_zoom(int k, int x, int y, t_data *data)
{
	double	zoom;

	zoom = 0;
	if (k >= MOUSE_LMB && k <= MOUSE_SCROLL_DOWN && x >= 0 && x < data->width
		&& y >= 0 && y < data->height)
	{
		if (k == MOUSE_SCROLL_UP)
			zoom = 1.05;
		else if (k == MOUSE_SCROLL_DOWN)
			zoom = 0.95;
		if (zoom * data->zoom >= data->min_zoom)
		{
			data->offset_x = (data->offset_x + (((data->width >> 1) - x)
						* zoom));
			data->offset_y = (data->offset_y + (((data->height >> 1) - y)
						* zoom));
			data->zoom *= zoom;
		}
		switch_julia_set(k, x, y, data);
		draw_fractal(data);
	}
	return (0);
}

void	switch_julia_set(int k, int x, int y, t_data *data)
{
	if (k == MOUSE_LMB || k == MOUSE_RMB)
	{
		data->seed = ((x * y) / ((data->width * data->height))) * (UINT_MAX);
		data->julia.real = (((double)x) / ((double)data->width)) * (2.00)
			+ -1.00;
		data->julia.imag = (((double)y) / ((double)data->height)) * (2.00)
			+ -1.00;
	}
}
