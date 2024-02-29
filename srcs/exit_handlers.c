/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:16:56 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/26 09:19:07 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_destroy(t_data *data, char *err)
{
	if (data->fractal_nb >= 0)
		free_histogram(data);
	ft_putendl_fd(err, 1);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void	exit_peacefully(void)
{
	ft_putendl_fd("\nWrong number of arguments", 1);
	ft_putendl_fd("Available fractals are:\n", 1);
	ft_putendl_fd("MANDEL	- Mandelbrot", 1);
	ft_putendl_fd("JULIA - Julia sets", 1);
	ft_putendl_fd("FLAME - Flame fractal\n", 1);
	exit(1);
}

void	exit_no_julia_params(void)
{
	ft_putendl_fd("\nWrong number of arguments", 1);
	ft_putendl_fd("Additional parameters needed for julia set coefficients:\n", 1);
	ft_putendl_fd("Example: ./fractol JULIA 0.285 0.01\n", 1);
	exit(1);
}