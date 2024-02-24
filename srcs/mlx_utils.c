/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:55:40 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/17 09:55:40 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	init_mlx_var(t_data *data, char *name)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "FRACTOL");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->offset_x = 0;
	data->offset_y = 0;
	data->menu_option = -1;
	data->color = SILVER;
	data->fill = BLACK;
	data->fractal_nb = -1;
	if (!data->mlx || !data->win || !data->addr || !check_set(data, name))
		return (0);
	else
		return (mem_allocate_histogram(data), 1);
}

void	reset_fractal(t_data *data)
{
	data->offset_x = 0;
	data->offset_y = 0;
	data->width = WIDTH;
	data->height = HEIGHT;
	check_set(data, NULL);
}

void	draw_fractal(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->min_x = ((data->offset_x + (data->width >> 1)) / (data->zoom / 2.00))
		/ -2.00;
	data->min_y = ((data->offset_y + (data->height >> 1)) / (data->zoom / 2.00))
		/ -2.00;
	ft_putendl_fd("RENDERING", 1);
	while (y < data->height && data->img && data->addr)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->fractal_nb < 2 && data->menu_option > 0 && x <= data
				->width - 10 && x >= data->width - 275
				&& y >= 10 && y <= 260)
				my_mlx_pixel_put(data, x, y, create_color(0, BLACK));
			else if (data->fractal_nb < 2 && data->menu_option < 0 && x
				<= data->width - 10 && x >= data->width - 275
				&& y >= 10 && y <= 30)
				my_mlx_pixel_put(data, x, y, create_color(0, BLACK));
			else
				setup_fractal(data, x, y);
			x++;
		}
		y++;
	}
	if (data->fractal_nb >= 2)
		plot_flames_histogram(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_menu(data);
	ft_putendl_fd("DONE", 1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	exit_destroy(t_data *data, char *err)
{
	free_histogram(data);
	ft_putendl_fd(err, 1);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}
