/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:38:06 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/24 13:38:06 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_flames_histogram(float x, float y, t_data *img)
{
	int		i;
	int		modified_w;
	int		modified_h;
	int		adjusted_x;
	int		adjusted_y;

	modified_w = (img->width >> 1);
	modified_h = (img->height >> 1);
	i = 0;
	x = x - modified_w;
	y = y - modified_h;
	while (i < img->max)
	{
		set_flame_plot(&x, &y, img);
		set_coefficients(&x, &y, i, img);
		adjusted_x = x + modified_w;
		adjusted_y = y + modified_h;
		if (adjusted_y >= 0 && adjusted_y < img->height && adjusted_x >= 0
			&& adjusted_x < img->width && i > 20)
			img->flame_hst[adjusted_y][adjusted_x].count++;
		i++;
	}
	return (i);
}

void	set_flame_plot(float *x, float *y, t_data *img)
{
	float	r;
	float	zero;

	r = sqrt((*x * *x + *y * *y));
	zero = atan2(*y, *x);
	*x = r * sin((zero + r));
	*y = r * cos((zero - r));
}

void	plot_flames_histogram(t_data *img)
{
	int			x;
	int			y;
	int			t_color;
	long long	max;

	y = 0;
	max = get_max_histogram(img) * img->color;
	ft_putendl_fd("PLOTTING FLAMES", 1);
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			t_color = ((img->flame_hst[y][x].count * img->color)
					/ (max)) * (255 - 0) + 0;
			if (t_color > 0)
				printf("%d\n",t_color);
			my_mlx_pixel_put(img, x, y, create_trgb(t_color, t_color, t_color,
					t_color));
			x++;
		}
		y++;
	}
}

unsigned int	simple_rand(unsigned int seed)
{
	unsigned long	next;

	next = (unsigned long)seed;
	next = next * 1103515245 + 12345;
	next = next % ((unsigned long)UINT_MAX + 1);
	return (next);
}

double	smoothstep(unsigned int seed)
{
	double	final;

	final = ((seed) / UINT_MAX);
	return (final);
}
