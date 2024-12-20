SRCS = ./srcs/main.c\
		./srcs/mandelbrot.c\
		./srcs/mlx_utils.c\
		./srcs/event_handlers.c\
		./srcs/colors.c\
		./srcs/julia.c\
		./srcs/key_events.c\
		./srcs/mouse_events.c\
		./srcs/menu.c\
		./srcs/flame.c\
		./srcs/histogram_functions.c\
		./srcs/interpolation_params.c\
		./srcs/interpolation.c\
		./srcs/setup_fractals.c\
		./srcs/exit_handlers.c
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/
PROGRAM = fractol
CC = cc
OBJECTS = ${SRCS:.c=.o}
MLX_INCLUDE = ./mlx/
LIBMLX = ./mlx/libmlx.a

LINUX: ${SRCS}
	echo "Compiling LIBFT archive"
	make -C ./libft fclean all clean
	mv ./libft/libft.a ./libft.a
	${CC} ${CFLAGS} -fsanitize=address -g3 ${SRCS} libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I ./ -o ${PROGRAM}

MAC: ${SRCS}
	echo "Compiling LIBFT archive"
	make -C ./libft fclean all clean
	mv ./libft/libft.a ./libft.a
	${CC} ${CFLAGS} -fsanitize=address -g3 ${SRCS} libft.a ${LIBMLX} -I ${INCLUDES} -I ${MLX_INCLUDE} -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${PROGRAM}

clean:
	echo "Cleaning files"
	make -C ./libft clean
	rm -f ${OBJECTS} ${NAME}

fclean:	clean
	echo "Cleaning files and removing archives and program"
	make -C ./libft fclean
	rm -f ${PROGRAM}
	rm -f libft.a

re:	fclean all

.PHONY:	all clean fclean re
