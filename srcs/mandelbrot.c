/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:55:38 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/17 09:55:38 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(double x, double y, t_data *img)
{
	int	m;

	m = mandelbrot(img);
	if (m == img->max)
		my_mlx_pixel_put(img, x, y, create_color(0, img->fill));
	else
		my_mlx_pixel_put(img, x, y, create_color(0, m * img->color));
}

int	mandelbrot(t_data *img)
{
	int		iterations;
	double	modulo;
	double	temp;

	iterations = 0;
	temp = 0;
	modulo = img->z.real * img->z.real + img->z.imag * img->z.imag;
	while ((modulo < 4) && (iterations < img->max))
	{
		temp = img->z.real;
		img->z.real = img->z.real * img->z.real - img->z.imag * img->z.imag + img->c.real;
		img->z.imag = 2 * img->z.imag * temp + img->c.imag;
		modulo = img->z.real * img->z.real + img->z.imag * img->z.imag;
		iterations++;
	}
	return (iterations);
}
