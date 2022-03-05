cmake_minimum_required(VERSION 3.21)
project(Cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(Cub3d
        srcs_b/libft/ft_atoi.c
        srcs_b/libft/ft_bzero.c
        srcs_b/libft/ft_calloc.c
        srcs_b/libft/ft_clear_array.c
        srcs_b/libft/ft_itoa_uns.c
        srcs_b/libft/ft_lst_addback.c
        srcs_b/libft/ft_lstclear.c
        srcs_b/libft/ft_lstdelone.c
        srcs_b/libft/ft_lstnew.c
        srcs_b/libft/ft_lstsize.c
        srcs_b/libft/ft_memset.c
        srcs_b/libft/ft_putendl_fd.c
        srcs_b/libft/ft_putstr_fd.c
        srcs_b/libft/ft_split.c
        srcs_b/libft/ft_strchr.c
        srcs_b/libft/ft_strchr_count.c
        srcs_b/libft/ft_strcmp.c
        srcs_b/libft/ft_strcpy.c
        srcs_b/libft/ft_strdup.c
        srcs_b/libft/ft_strjoin.c
        srcs_b/libft/ft_strlen.c
        srcs_b/libft/ft_strncmp.c
        srcs_b/libft/ft_strrchr.c
        srcs_b/libft/ft_strtrim.c
        srcs_b/libft/ft_substr.c
        srcs_b/libft/get_next_line.c

        hdrs/cub3d_bonus.h main_b.c
        srcs_b/3d/draw_ceil.c
        srcs_b/3d/draw_lightning.c
        srcs_b/3d/draw_walls.c
        srcs_b/input/g_do_keys.c
        srcs_b/input/mouse_keys.c
        srcs_b/input/mouse_pos.c
        srcs_b/interface/draw_battery_bar.c
        srcs_b/interface/draw_end_screen.c
        srcs_b/interface/draw_health_effect.c
        srcs_b/interface/draw_interface.c
        srcs_b/interface/draw_menu_screen.c
        srcs_b/interface/draw_start_screen.c
        srcs_b/ray_cast/draw_minimap_elements.c
        srcs_b/ray_cast/draw_round_minimap.c
        srcs_b/ray_cast/ray_cast.c
        srcs_b/ray_cast/utils.c
        srcs_b/parsing/m_atoi.c
        srcs_b/parsing/m_check_fname.c
        srcs_b/parsing/m_check_map.c
        srcs_b/parsing/m_check_param.c
        srcs_b/parsing/m_error.c
        srcs_b/parsing/m_init_map.c
        srcs_b/parsing/m_lst.c
        srcs_b/parsing/m_pars.c
        srcs_b/parsing/m_pars_map.c
        srcs_b/parsing/m_pars_param.c
        srcs_b/parsing/m_rgb.c
        srcs_b/parsing/m_file_to_image.c
#


#        _bonus/main_bonus.c hdrs/cub3d_bonus.h
#        _bonus/srcs_b/parsing/m_add_vilian.c
#        _bonus/srcs_b/parsing/m_atoi.c
#        _bonus/srcs_b/parsing/m_check_fname.c
#        _bonus/srcs_b/parsing/m_check_map.c
#        _bonus/srcs_b/parsing/m_check_param.c
#        _bonus/srcs_b/parsing/m_init_map.c
#        _bonus/srcs_b/parsing/m_pars.c
#        _bonus/srcs_b/parsing/m_pars_map.c
#        _bonus/srcs_b/parsing/m_pars_param.c
#        _bonus/srcs_b/parsing/m_rgb.c
#        srcs_b/parsing/m_error.c
#        srcs_b/parsing/m_lst.c
#        _bonus/srcs_b/enemy/m_move_enemy.c
#        _bonus/ray_cast/draw_minimap_elements.c
#        _bonus/ray_cast/draw_round_minimap.c
#        _bonus/ray_cast/ray_cast.c
#        _bonus/ray_cast/utils.c
#
#        _bonus/srcs_b/enemy/utils.c _bonus/srcs_b/parsing/m_file_to_image.c
        srcs/3d/utils.c srcs/3d/L3d.h srcs/3d/get_color.c srcs/3d/draw_walls_test.c srcs/3d/draw_walls.c srcs/input/key_utils.c srcs_b/3d/draw_enemy.c)

target_link_libraries(Cub3d /Users/mseastar/CLionProjects/Cub3d/libmlx.a "-framework OpenGL" "-framework AppKit")

