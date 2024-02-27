/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:39:09 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 15:39:09 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	specific_menu(t_data *data)
{
	if (data->fractal_nb == 1)
	{
		mlx_string_put(data->mlx, data->win, data->width - 250, 250, WHITE,
			"Select Julia : Click on the screen");
	}
}

void	draw_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->width - 250, 25, WHITE,
		"Display Menu : Press [H] Button");
	if (data->menu_option > 0)
	{
		mlx_string_put(data->mlx, data->win, data->width - 250, 75, WHITE,
			"Zoom In : Scroll up");
		mlx_string_put(data->mlx, data->win, data->width - 250, 100, WHITE,
			"Zoom Out : Scroll down");
		mlx_string_put(data->mlx, data->win, data->width - 250, 125, WHITE,
			"Change Colors : Press Numbers [1-9]");
		mlx_string_put(data->mlx, data->win, data->width - 250, 150, WHITE,
			"Move view : Press Arrow keys");
		mlx_string_put(data->mlx, data->win, data->width - 250, 175, WHITE,
			"Previous Fractal : Press [<] Button");
		mlx_string_put(data->mlx, data->win, data->width - 250, 200, WHITE,
			"Next Fractal : Press [>] Button");
		mlx_string_put(data->mlx, data->win, data->width - 250, 225, WHITE,
			"Reset Display : Press [R] Button");
		specific_menu(data);
	}
}
