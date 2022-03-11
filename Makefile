CC			=	gcc
#-Wall -Wextra -Werror
FLAGS		=	-Wall -Wextra -Werror
FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	cub3d
NAME_B 	=	cub3d_bonus
LIB		=	cub3d.a
LIB_B	=	cub3d_bonus.a

HDRS	=	cub3d.h
HDRS_B	=	cub3d_bonus.h

FLDR_S	=	srcs/
FLDR_B	=	srcs_b/
FLDR_H	=	hdrs/

MAIN	=	main.c
MAIN_B	=	main_b.c

SRCS	=	libft/ft_strlen.c			libft/ft_calloc.c				libft/ft_bzero.c				\
			libft/ft_strcpy.c			libft/ft_strdup.c				libft/ft_clear_array.c			\
			libft/ft_split.c			libft/ft_strchr_count.c			libft/ft_strncmp.c				\
			libft/get_next_line.c		libft/ft_strjoin.c				libft/ft_strchr.c				\
			libft/ft_substr.c			libft/ft_memset.c				libft/ft_strtrim.c				\
			libft/ft_strcmp.c			\
			ray_cast/utils.c			ray_cast/ray_cast.c				\
			input/g_do_keys.c			input/key_utils.c				\
			3d/draw_walls.c				3d/draw_ceil.c					3d/draw_floor.c					\
			3d/utils.c					\
			parsing/m_atoi.c			parsing/m_check_fname.c			parsing/m_check_map.c			\
			parsing/m_check_param.c		parsing/m_init_map.c			parsing/m_pars.c				\
			parsing/m_pars_map.c		parsing/m_pars_param.c			parsing/m_rgb.c					\
			parsing/m_error.c			parsing/m_lst.c					parsing/m_file_to_image.c		\
			parsing/m_clear_all.c

SRCS_B	=	libft/ft_strlen.c				libft/ft_strcpy.c				libft/ft_strdup.c				\
			libft/ft_calloc.c				libft/ft_clear_array.c			libft/ft_split.c				\
			libft/ft_strchr_count.c			libft/ft_strncmp.c				libft/get_next_line.c			\
			libft/ft_bzero.c				libft/ft_strchr.c				libft/ft_strjoin.c				\
			libft/ft_substr.c				libft/ft_memset.c				libft/ft_strtrim.c				\
			libft/ft_strcmp.c				\
			minimap/utils.c					minimap/draw_minimap_elements.c	minimap/draw_round_minimap.c	\
			minimap/ray_cast.c				\
			input/g_do_keys.c				input/mouse_pos.c				input/mouse_keys.c				\
			input/key_utils.c				\
			interface/draw_interface.c		interface/draw_menu_screen.c	interface/draw_health_effect.c	\
			interface/draw_start_screen.c	interface/draw_battery_bar.c	interface/draw_wand_and_light.c	\
			interface/draw_end_screen.c		\
			interface/utils.c				\
			3d/draw_walls.c					3d/draw_ceil.c					3d/draw_floor.c					\
			3d/ray_cast_for_tex.c			3d/utils.c						3d/utils2.c\
			parsing/m_atoi.c				parsing/m_check_fname.c			parsing/m_check_map.c			\
			parsing/m_check_param.c			parsing/m_init_map.c			parsing/m_pars.c				\
			parsing/m_pars_map.c			parsing/m_pars_param.c			parsing/m_rgb.c					\
			parsing/m_error.c				parsing/m_lst.c					parsing/m_file_to_image.c		\
			parsing/m_add_vilian.c			parsing/m_clear_all.c			parsing/m_init_imgs.c			\
			parsing/init_all.c				\
			enemy/m_enemy_action.c      	enemy/utils.c					enemy/m_enemy_atack.c 			\
			enemy/m_move_enemy.c			enemy/m_draw_enemy_minimap.c	enemy/m_player_attack.c


SRC		=	$(addprefix ${FLDR_S},${SRCS})
SRCB	=	$(addprefix ${FLDR_B},${SRCS_B})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
OBJS	=	${SRC:%.c=%.o}
OBJS_B	=	${SRCB:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	Cub3d is ready
READYB	=	Cub3d_bonus is ready
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
			@${MAKE} clean -C mlx
			@${RM} ${OBJS} ${OBJS_B}
			@printf "${_PURPLE}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${NAME_B} ${LIB} ${LIB_B} libmlx.a

re:			fclean all

bonus:
			@make OBJS="${OBJS_B}" LIB="${LIB_B}" MAIN="${MAIN_B}" NAME="${NAME_B}" READY="${READYB}" all


norm:
			@norminette ${MAIN} ${MAIN_B} ${FLDR_H} ${FLDR_S} ${FLDR_B}
#			@norminette ${MAIN} ${FLDR_H} ${FLDR_S}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus