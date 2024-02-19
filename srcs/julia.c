/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:48:05 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:05 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(double x, double y, t_data *img)
{
	int	m;

	m = julia(img);
	if (m == img->max)
		my_mlx_pixel_put(img, x, y, create_color(0, img->fill));
	else
		my_mlx_pixel_put(img, x, y, create_color(0, m * img->color));
}

int	julia(t_data *img)
{
	int		iterations;
	double	modulo;
	double	temp;
	iterations = 0;
	temp = 0;
	modulo = sqrtf(img->c.real * img->c.real + img->c.imag * img->c.imag);
	while ((modulo < 4) && (iterations < img->max))
	{
		temp = img->c.real;
		img->c.real = img->c.real * img->c.real - img->c.imag * img->c.imag + img->julia.real;
		img->c.imag = 2 * img->c.imag * temp + img->julia.imag;
		modulo = sqrtf(img->c.real * img->c.real + img->c.imag * img->c.imag);
		iterations++;
	}
	return (iterations);
}
