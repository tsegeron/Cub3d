cmake_minimum_required(VERSION 3.21)
project(Cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(Cub3d
        srcs/libft/ft_atoi.c
        srcs/libft/ft_bzero.c
        srcs/libft/ft_calloc.c
        srcs/libft/ft_clear_array.c
        srcs/libft/ft_itoa_uns.c
        srcs/libft/ft_lst_addback.c
        srcs/libft/ft_lstclear.c
        srcs/libft/ft_lstdelone.c
        srcs/libft/ft_lstnew.c
        srcs/libft/ft_lstsize.c
        srcs/libft/ft_memset.c
        srcs/libft/ft_putendl_fd.c
        srcs/libft/ft_putstr_fd.c
        srcs/libft/ft_split.c
        srcs/libft/ft_strchr.c
        srcs/libft/ft_strchr_count.c
        srcs/libft/ft_strcmp.c
        srcs/libft/ft_strcpy.c
        srcs/libft/ft_strdup.c
        srcs/libft/ft_strjoin.c
        srcs/libft/ft_strlen.c
        srcs/libft/ft_strncmp.c
        srcs/libft/ft_strrchr.c
        srcs/libft/ft_strtrim.c
        srcs/libft/ft_substr.c
        srcs/libft/get_next_line.c

        hdrs/cub3d.h main.c
        srcs/3d/draw_ceil.c
        srcs/3d/draw_lightning.c
        srcs/3d/draw_walls.c
        srcs/input/g_do_keys.c
        srcs/input/mouse_keys.c
        srcs/input/mouse_pos.c
        srcs/interface/draw_battery_bar.c
        srcs/interface/draw_end_screen.c
        srcs/interface/draw_health_effect.c
        srcs/interface/draw_interface.c
        srcs/interface/draw_menu_screen.c
        srcs/interface/draw_start_screen.c
        srcs/minimap/draw_minimap_elements.c
        srcs/minimap/draw_round_minimap.c
        srcs/minimap/ray_cast.c
        srcs/minimap/utils.c
        srcs/parsing/m_atoi.c
        srcs/parsing/m_check_fname.c
        srcs/parsing/m_check_map.c
        srcs/parsing/m_check_param.c
        srcs/parsing/m_error.c
        srcs/parsing/m_init_map.c
        srcs/parsing/m_lst.c
        srcs/parsing/m_pars.c
        srcs/parsing/m_pars_map.c
        srcs/parsing/m_pars_param.c
        srcs/parsing/m_rgb.c
        srcs/parsing/m_file_to_image.c
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
#        _bonus/minimap/draw_minimap_elements.c
#        _bonus/minimap/draw_round_minimap.c
#        _bonus/minimap/ray_cast.c
#        _bonus/minimap/utils.c
#
#        _bonus/srcs_b/enemy/utils.c _bonus/srcs_b/parsing/m_file_to_image.c
        srcs/3d/utils.c srcs/3d/L3d.h srcs/3d/get_color.c srcs/3d/draw_walls_test.c srcs/3d/draw_walls_test2.c)

target_link_libraries(Cub3d /Users/mseastar/CLionProjects/Cub3d/libmlx.a "-framework OpenGL" "-framework AppKit")

