/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:48:08 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:08 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_color(int k, t_data *data)
{
	if (KEY_1 == k)
		data->color = GOLDEN_ROD;
	else if (KEY_2 == k)
		data->color = AQUA_MARINE;
	else if (KEY_3 == k)
		data->color = DARK_MAGENTA;
	else if (KEY_4 == k)
		data->color = ORCHID;
	else if (KEY_5 == k)
		data->color = ANTIQUE_WHITE;
	else if (KEY_6 == k)
		data->color = LAVENDER;
	else if (KEY_7 == k)
		data->color = MISTY_ROSE;
	else if (KEY_8 == k)
		data->color = GAINSBORO;
	else if (KEY_9 == k)
		data->color = SILVER;
}

void	switch_fractal(int k, t_data *data)
{
	if (k == KEY_LT && data->fractal_nb > 0)
		data->fractal_nb--;
	else if (k == KEY_GT && data->fractal_nb < 3)
		data->fractal_nb++;
	if (data->fractal_nb >= 2 && data->fractal_nb <= 3)
		paint_it_black(data);
	check_set(data, NULL);
}

void	movement(int k, t_data *data)
{
	if (k == KEY_UP)
		data->offset_y += (0.1 * data->zoom);
	else if (k == KEY_DOWN)
		data->offset_y -= (0.1 * data->zoom);
	else if (k == KEY_RIGHT)
		data->offset_x -= (0.1 * data->zoom);
	else if (k == KEY_LEFT)
		data->offset_x += (0.1 * data->zoom);
}
