/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:20:37 by gponti-s          #+#    #+#             */
/*   Updated: 2021/07/25 10:22:09 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"

# define SCALE 75
# define MIN_SCALE 75

typedef struct s_data {
	char	*relative_path;
	char	*relative_path2;
	char	*relative_path3;
	char	*relative_path4;
	char	*relative_path5;
	char	*relative_path6;
	char	*relative_path7;
	char	*relative_path8;
	void	*img;
	char	*addr;
	void	*win;
	void	*mlx;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		game_over;
	int		fd;
	int		large;
	int		height;
	int		large_y;
	int		height_x;
	char	**ptr;
	int		argc;
	int		x;
	int		y;
	int		z;
	int		count_mov;
	int		score;
	int		exit;
	int		sprit;
	int		error_retangle;
	void	*dolphin;
	void	*dolphin2;
	void	*wall;
	void	*sea;
	void	*fish;
	void	*shell;
	void	*hook;
	void	*open_shell;
	int		error_player;
	int		error_colec;
	int		error_exit;
}				t_data;

void	define_image_path(t_data *img);
void	inicializa_stracte(t_data *img);
// frame.c
int		create_trgb(int t, int r, int g, int b);
int		render_next_frame_sea(t_data *img);
void	render_image(t_data *img, int x, int y, char image);
void	print_inf(t_data *img);
void	print_end(t_data *img);
void	render_image_dolphin(t_data *img, int x, int y);

//movement.c
int		key_hook(int keycode, t_data *vars);
int		key_hook_mouse(int keycode, int x, int y, t_data *vars);
int		my_close(int keycode, t_data *vars);
int		my_close_x(int keycode, t_data *vars);
void	movement_check(int keycode, t_data *vars, int x, int y);

//get_map.c
void	get_map(t_data *img, char *argv);
void	scale(t_data *img);

//game_rules.c
void	game_rules_up(t_data *vars, int x, int y);
void	game_rules_down(t_data *vars, int x, int y);
void	game_rules_left(t_data *vars, int x, int y);
void	game_rules_right(t_data *vars, int x, int y);

//print_terminal.c
void	print_score(t_data *vars);
void	print_count_mov(t_data *vars);

//error_handler.c
void	error_handler_argc(int argc);
void	error_handler_map(t_data *vars);
int		error_handler_wall(t_data *vars);
int		error_handler_character(t_data *vars);
void	free_map(t_data *vars);
#endif
