/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:55:36 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/17 09:55:36 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && init_mlx_var(&data, argv[1]))
		draw_fractal(&data);
	else
		exit_destroy(&data, "Usage not correct");
	mlx_mouse_hook(data.win, scroll_zoom, &data);
	mlx_hook(data.win, 2, 1L << 0, keybinds, &data);
	mlx_loop(data.mlx);
	return (1);
}