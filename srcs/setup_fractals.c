/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:00:39 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/26 08:15:58 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_flame_set(t_data *data, char *name)
{
	data->min_zoom = 0;
	data->zoom = 8;
	data->seed = 24;
	if (data->fractal_nb == 2 || (name && !ft_strcmp("FLAME", name)))
		data->fractal_nb = 2;
	else if (data->fractal_nb == 3 || (name && !ft_strcmp("FLAME2", name)))
		data->fractal_nb = 3;
	else if (data->fractal_nb == 4 || (name && !ft_strcmp("FLAME3", name)))
		data->fractal_nb = 4;
	else
		return (0);
	return (1);
}

static int	check_julia_set(t_data *data, char *name, char **argv)
{
	if (name)
	{
		data->julia.real = ft_strtod(argv[2]);
		data->julia.imag = ft_strtod(argv[3]);
	}
	else
	{	
		data->julia.real = -0.506667;
		data->julia.imag = 0.520000;
	}
	return (1);
}

int	check_set(t_data *data, char *name, char **argv)
{
	data->zoom = 300;
	data->min_zoom = 300;
	data->max = 150;
	if (data->fractal_nb == 0 || (name && !ft_strcmp("MANDEL", name)))
		data->fractal_nb = 0;
	else if (data->fractal_nb == 1 || (name && !ft_strcmp("JULIA", name)))
	{
		data->fractal_nb = 1;
		data->offset_x = 60;
		data->offset_y = 40;
		check_julia_set(data, name, argv);
	}
	else
		return (check_flame_set(data, name));
	return (1);
}

void	setup_fractal(t_data *data, int x, int y)
{
	data->z.real = 0;
	data->z.imag = 0;
	data->c.real = ((double)x / (double)data->zoom) + (double)data->min_x;
	data->c.imag = ((double)y / (double)data->zoom) + (double)data->min_y;
	if (data->fractal_nb == 0)
		draw_mandelbrot((double)x, (double)y, data);
	else if (data->fractal_nb == 1)
		draw_julia((double)x, (double)y, data);
	else if (data->fractal_nb >= 2)
	{
		coefficient_init(data);
		create_flames_histogram((double)x, (double)y, data);
	}
	else
		exit_destroy(data, "Usage not correct");
}
