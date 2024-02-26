/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:55:31 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/17 09:55:31 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "key_binds.h"
# include "color_key.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# define HEIGHT 720
# define WIDTH 1280

//complex number
typedef struct s_cmplx {
	double	real;
	double	imag;
}				t_cmplx;

//histogram for flame fractals
typedef struct s_histogram {
	long long	count;
}				t_histogram;

//flame fractal coefficients
typedef struct s_coefficients {
	double	scale_x;
	double	rotation_x;
	double	shift_x;
	double	scale_y;
	double	rotation_y;
	double	shift_y;
}				t_coefficients;

//data needed for rendering fractals
typedef struct s_data {
	int				fractal_nb;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			zoom;
	double			min_zoom;
	int				max;
	int				width;
	int				height;
	unsigned int	seed;
	int				color;
	int				fill;
	int				menu_option;
	double			min_x;
	double			min_y;
	double			offset_x;
	double			offset_y;
	int				img_scale_max_x;
	int				img_scale_min_x;
	int				img_scale_max_y;
	int				img_scale_min_y;
	t_coefficients	result_coef;
	t_coefficients	*flame_coef;
	t_histogram		**flame_hst;
	t_cmplx			julia;
	t_cmplx			c;
	t_cmplx			z;
}				t_data;

//Fractal drawing functions

//Takes in a complex number and returns the iterations
//needed to reach a mod value of C that is greater than 2.
void			draw_mandelbrot(double x, double y, t_data *img);
int				mandelbrot(t_data *img);

void			draw_julia(double x, double y, t_data *img);
void			switch_julia_set(int k, int x, int y, t_data *data);
int				julia(t_data *img);

int				create_flames_histogram(double x, double y, t_data *img);
void			plot_flames_histogram(t_data *img);
int				get_max_histogram(t_data *img);
int				mem_allocate_histogram(t_data *img);
int				free_histogram(t_data *img);
void			coefficient_init(t_data *data);
unsigned int	simple_rand(unsigned int seed);
double			smoothstep(unsigned int seed);
double			interpolate(double *params);
void			cosine_interpolation(t_data *data, int i,
					t_coefficients *result);
void			set_coefficients(double *x, double *y, int i, t_data *img);
void			set_flame_plot(double *x, double *y, t_data *img);

double			*params_assign_scale(double *params, t_data *data, int i,
					char c);
double			*params_assign_rotation(double *params, t_data *data, int i,
					char c);
double			*params_assign_shift(double *params, t_data *data, int i,
					char c);

//Color functions

int				get_t_color(int color);
int				get_red_color(int color);
int				get_green_color(int color);
int				get_blue_color(int color);
void			set_color(int k, t_data *data);
int				create_trgb(int t, int r, int g, int b);
int				create_color(int t, int color);

//Menu functions, including keyboard and mouse controls

void			exit_destroy(t_data *data, char *err);
void			exit_peacefully(void);
void			draw_menu(t_data *data);
void			movement(int k, t_data *data);
int				check_set(t_data *data, char *name);
int				keybinds(int k, t_data *data);
int				scroll_zoom(int k, int x, int y, t_data *data);
int				flame_zoom(int k, int x, int y, t_data *data);
int				no_event(t_data *data);
int				close_window(t_data *data);
void			switch_fractal(int k, t_data *data);

//mlx init and fractal setup functions

void			setup_fractal(t_data *data, int x, int y);
int				init_mlx_var(t_data *data, char *name);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_fractal(t_data *data);
void			finalize_image(t_data *data);
void			reset_fractal(t_data *data);
void			paint_it_black(t_data *img);

#endif
