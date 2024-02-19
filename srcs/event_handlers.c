/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:25:32 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/19 14:37:13 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keybinds(int k, t_data *data)
{
	if (k == KEY_R)
		reset_fractal(data);
	if (k == KEY_H)
		data->menu_option *= -1;
	if (k == KEY_I)
		data->interpolate_option *= -1;
	if (k == KEY_ESCAPE)
		exit_destroy(data, "Exiting Program.");
	set_color(k, data);
	movement(k, data);
	switch_fractal(k, data);
	printf("(%d)\n", k);
	draw_fractal(data);
	return (1);
}

void	paint_it_black(t_data *img)
{
	int			x;
	int			y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			my_mlx_pixel_put(img, x, y, create_color(0, 0xFFFFFF));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	no_event(t_data *data)
{
	(void) data;
    return (0);
}
