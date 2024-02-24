/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histogram_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:48:00 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:00 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_max_histogram(t_data *img)
{
	int			x;
	int			y;
	int			t_color;

	y = 0;
	t_color = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (img->flame_hst[y][x].count > t_color)
				t_color = img->flame_hst[y][x].count;
			x++;
		}
		y++;
	}
	return (t_color);
}

int	mem_allocate_histogram(t_data *img)
{
	int	y;
	int	x;

	y = -1;
	img->flame_hst = malloc(img->height * sizeof(t_histogram *));
	img->flame_coef = malloc(img->max * sizeof(t_coefficients));
	while (++y < img->height)
		img->flame_hst[y] = malloc(img->width * sizeof(t_histogram));
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			img->flame_hst[y][x].count = 0;
	}
	return (1);
}

int	free_histogram(t_data *img)
{
	int	y;

	y = 0;
	while (y < img->height)
	{
		free(img->flame_hst[y]);
		y++;
	}
	free(img->flame_hst);
	return (1);
}
