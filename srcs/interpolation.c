/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:44:09 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/01 11:30:23 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	interpolate(double *params)
{
	double	mu2;
	double	a0;
	double	a1;
	double	a2;
	double	a3;

	mu2 = params[4] * params[4];
	a0 = params[3] - params[2] - params[0] + params[1];
	a1 = params[0] - params[1] - a0;
	a2 = params[2] - params[0];
	a3 = params[1];
	return (a0 * params[4] * mu2 + a1 * mu2 + a2 * params[4] + a3);
}

void	cosine_interpolation(t_data *data, int i, t_coefficients *result)
{
	double	params[5];

	result->scale_x = interpolate(params_assign_scale(params, data, i, 'x'));
	result->rotation_x = interpolate(params_assign_rotation(params, data, i,
				'x'));
	result->shift_x = interpolate(params_assign_shift(params, data, i, 'x'));
	result->scale_y = interpolate(params_assign_scale(params, data, i, 'y'));
	result->rotation_y = interpolate(params_assign_rotation(params, data, i,
				'y'));
	result->shift_y = interpolate(params_assign_shift(params, data, i, 'y'));
}

void	coefficient_init(t_data *data)
{
	double			seed;
	int				i;
	double			z;

	z = data->zoom + 0.00;
	i = -1;
	seed = simple_rand(data->seed) + 0.00;
	while (++i < data->max)
	{
		data->flame_coef[i].scale_x = (seed / (UINT_MAX)) * (2) + -1.00;
		seed = simple_rand(seed) + 0.00;
		data->flame_coef[i].rotation_x = (seed / (UINT_MAX)) * (2) - 1.00;
		seed = simple_rand(seed) + 0.00;
		data->flame_coef[i].shift_x = ((seed / (UINT_MAX)) * ((data->width
						/ z) - -(data->width / z)) + -(data->width / z));
		seed = simple_rand(seed) + 0.00;
		data->flame_coef[i].scale_y = (seed / (UINT_MAX)) * (2) + -1.00;
		seed = simple_rand(seed) + 0.00;
		data->flame_coef[i].rotation_y = (seed / (UINT_MAX)) * (2) + -1.00;
		seed = simple_rand(seed) + 0.00;
		data->flame_coef[i].shift_y = ((seed / (UINT_MAX)) * ((data->height
						/ z) - -(data->height / z)) + -(data->height / z));
		seed = simple_rand(seed) + 0.00;
	}
}

void	set_coefficients(double *x, double *y, int i, t_data *img)
{
	if (i >= 3)
	{
		cosine_interpolation(img, i, &img->result_coef);
		*x = img->result_coef.scale_x * *x + img->result_coef.rotation_x * *y
			+ img->result_coef.shift_x;
		*y = img->result_coef.scale_y * *x + img->result_coef.rotation_y * *y
			+ img->result_coef.shift_y;
	}
	else
	{
		*x = img->flame_coef[i].scale_x * *x + img->flame_coef[i].rotation_x
			* *y + img->flame_coef[i].shift_x;
		*y = img->flame_coef[i].scale_y * *x + img->flame_coef[i].rotation_y
			* *y + img->flame_coef[i].shift_y;
	}
}
