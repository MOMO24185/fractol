/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:47:48 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:47:48 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	*params_assign_scale(double *params, t_data *data, int i, char c)
{
	unsigned int	seed;

	data->seed = simple_rand(data->seed);
	seed = simple_rand(data->seed);
	if (c == 'x')
	{
		params[0] = data->flame_coef[i].scale_x;
		params[1] = data->flame_coef[i - 1].scale_x;
		params[2] = data->flame_coef[i - 2].scale_x;
		params[3] = data->flame_coef[i - 3].scale_x;
		params[4] = smoothstep(seed);
	}
	else if (c == 'y')
	{
		params[0] = data->flame_coef[i].scale_y;
		params[1] = data->flame_coef[i - 1].scale_y;
		params[2] = data->flame_coef[i - 2].scale_y;
		params[3] = data->flame_coef[i - 3].scale_y;
		params[4] = smoothstep(seed);
	}
	return (params);
}

double	*params_assign_rotation(double *params, t_data *data, int i, char c)
{
	unsigned int	seed;

	data->seed = simple_rand(data->seed);
	seed = simple_rand(data->seed);
	if (c == 'x')
	{
		params[0] = data->flame_coef[i].rotation_x;
		params[1] = data->flame_coef[i - 1].rotation_x;
		params[2] = data->flame_coef[i - 2].rotation_x;
		params[3] = data->flame_coef[i - 3].rotation_x;
		params[4] = smoothstep(seed);
	}
	else if (c == 'y')
	{
		params[0] = data->flame_coef[i].rotation_y;
		params[1] = data->flame_coef[i - 1].rotation_y;
		params[2] = data->flame_coef[i - 2].rotation_y;
		params[3] = data->flame_coef[i - 3].rotation_y;
		params[4] = smoothstep(seed);
	}
	return (params);
}

double	*params_assign_shift(double *params, t_data *data, int i, char c)
{
	unsigned int	seed;

	data->seed = simple_rand(data->seed);
	seed = simple_rand(data->seed);
	if (c == 'x')
	{
		params[0] = data->flame_coef[i].shift_x;
		params[1] = data->flame_coef[i - 1].shift_x;
		params[2] = data->flame_coef[i - 2].shift_x;
		params[3] = data->flame_coef[i - 3].shift_x;
		params[4] = smoothstep(seed);
	}
	else if (c == 'y')
	{
		params[0] = data->flame_coef[i].shift_y;
		params[1] = data->flame_coef[i - 1].shift_y;
		params[2] = data->flame_coef[i - 2].shift_y;
		params[3] = data->flame_coef[i - 3].shift_y;
		params[4] = smoothstep(seed);
	}
	return (params);
}
