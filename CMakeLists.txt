cmake_minimum_required(VERSION 3.21)
project(Cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(Cub3d
        srcs_b/libft/ft_bzero.c
        srcs_b/libft/ft_calloc.c
        srcs_b/libft/ft_clear_array.c
        srcs_b/libft/ft_memset.c
        srcs_b/libft/ft_split.c
        srcs_b/libft/ft_strchr.c
        srcs_b/libft/ft_strchr_count.c
        srcs_b/libft/ft_strcmp.c
        srcs_b/libft/ft_strcpy.c
        srcs_b/libft/ft_strdup.c
        srcs_b/libft/ft_strjoin.c
        srcs_b/libft/ft_strlen.c
        srcs_b/libft/ft_strncmp.c
        srcs_b/libft/ft_strtrim.c
        srcs_b/libft/ft_substr.c
        srcs_b/libft/get_next_line.c

        hdrs/cub3d_bonus.h main_b.c
        srcs_b/3d/draw_ceil.c
        srcs_b/3d/draw_floor.c
        srcs_b/3d/draw_walls.c
        srcs_b/3d/utils.c
        srcs_b/enemy/m_draw_enemy_minimap.c
        srcs_b/enemy/m_enemy_action.c
        srcs_b/enemy/m_enemy_atack.c
        srcs_b/enemy/m_move_enemy.c
        srcs_b/enemy/m_player_attack.c
        srcs_b/enemy/utils.c
        srcs_b/input/g_do_keys.c
        srcs_b/input/mouse_keys.c
        srcs_b/input/mouse_pos.c
        srcs_b/input/key_utils.c
        srcs_b/interface/draw_battery_bar.c
        srcs_b/interface/draw_end_screen.c
        srcs_b/interface/draw_health_effect.c
        srcs_b/interface/draw_interface.c
        srcs_b/interface/draw_menu_screen.c
        srcs_b/interface/draw_start_screen.c
        srcs_b/minimap/draw_minimap_elements.c
        srcs_b/minimap/draw_round_minimap.c
        srcs_b/minimap/ray_cast.c
        srcs_b/minimap/utils.c
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
        srcs_b/parsing/m_add_vilian.c
        srcs_b/parsing/m_clear_all.c
        srcs_b/parsing/m_init_imgs.c
        srcs_b/interface/draw_wand_and_light.c srcs_b/interface/utils.c srcs_b/3d/ray_cast_for_tex.c srcs_b/3d/utils2.c)

target_link_libraries(Cub3d /Users/tsegeron/Desktop/Cub3d/libmlx.a "-framework OpenGL" "-framework AppKit")
