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

SRCS	=	libft/ft_strlen.c			libft/ft_strcpy.c				libft/ft_strdup.c			\
			minimap/draw_minimap.c		g_do_keys.c
#			parsing/m_check_fname.c		parsing/m_check_map.c			parsing/m_init_map.c		\
#			parsing/m_pars.c			parsing/m_pars_map.c			parsing/m_pars_param.c		\
#			parsing/m_rerror_r.c		\
#			libfts/ft_bzero.c				libfts/ft_calloc.c			\
#			libfts/ft_strjoin.c			libfts/ft_itoa_uns.c			libfts/ft_strtrim.c			\
#			libfts/ft_putendl_fd.c		libfts/ft_strcmp.c				\
#			libfts/ft_putstr_fd.c			libfts/ft_atoi.c			\
#			libfts/ft_strchr.c			libfts/ft_substr.c				libfts/ft_split.c			\
#			libfts/ft_strchr_count.c	libfts/ft_strncmp.c				libfts/ft_strrchr.c			\


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
			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} libmlx.a -o ${NAME}
			@printf "${_CYAN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "${_PURPLE}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${LIB} ${NAME_U}

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