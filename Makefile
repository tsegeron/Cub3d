CC			=	gcc
#-Wall -Wextra -Werror
#FLAGS		=	-Wall -Wextra -Werror
FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	cub3d
LIB		=	cub3d.a
#LIB1	=	libft.a
#LIB2	=	pipex.a

HDRS	=	cub3d.h
#HDRS_B	=	so_long_b.h

FLDR_S	=	srcs/
#FLDR_B	=	srcs_b/
FLDR_H	=	hdrs/

MAIN	=	main.c
#MAIN	=	test.c
#MAIN_B	=	checker.c

SRCS	=	libft/ft_strlen.c			libft/ft_strcpy.c				libft/ft_strdup.c				\
			minimap/ray_cast.c			minimap/draw_minimap_elements.c	minimap/draw_round_minimap.c	\
			minimap/utils.c				\
			input/g_do_keys.c			input/mouse_pos.c		\
			interface/draw_interface.c	interface/draw_battery_bar.c	interface/draw_health_effect.c	\



SRC		=	$(addprefix ${FLDR_S},${SRCS})
#SRCB	=	$(addprefix ${FLDR_B},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
#HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
OBJS	=	${SRC:%.c=%.o}
#OBJS_B	=	${SRCB:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	Cub3d is ready
#READYB	=	Checker is ready
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_PURPLE	=	\e[0;35m
_CYAN	=	\e[0;36m
_END	=	\e[33m

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c	${HDR}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


${NAME}: 	${OBJS} ${MAIN}
			@${AR} ${LIB} $?
			@${MAKE} -C mlx
			@cp mlx/libmlx.a libmlx.a
			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} libmlx.a -o ${NAME}
			@printf "${_CYAN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "${_PURPLE}${SWEPT}${_END}\n"

fclean:		clean
			@${MAKE} clean -C mlx
			@${RM} ${NAME} ${LIB} ${NAME_U} libmlx.a

re:			fclean all

bonus:		${OBJS}
#			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN_B} ${LIB} -o ${NAME_B}
			@printf "${_GREEN}${READYB}${_END}\n"

#main:
#			@${CC} ${FLAGS} ${OPTFLAGS} main.c ${LIB}

#test:
#			@${CC} ${FLAGS} ${OPTFLAGS} test.c ${LIB}

norm:
			@norminette ${MAIN} ${FLDR_H} ${FLDR_S}


#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus