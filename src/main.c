/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:49:14 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/08 12:45:05 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	img;

	error_handler_argc(argc);
	inicializa_stracte(&img);
	get_map(&img, argv[1]);
	error_handler_map(&img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, (img.large), (img.height), "so_long");
	img.img = mlx_new_image(img.mlx, (img.large), (img.height));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	define_image_path(&img);
	mlx_loop_hook(img.mlx, render_next_frame_sea, &img);
	mlx_hook(img.win, 2, 1L << 0, my_close, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 0, my_close_x, &img);
	mlx_loop(img.mlx);
}

void	inicializa_stracte(t_data *img)
{
	img->game_over = 0;
	img->count_mov = 0;
	img->score = 0;
	img->exit = 0;
	img->sprit = 0;
	img->error_retangle = 0;
	img->x = 0;
	img->y = 0;
	img->z = 0;
	img->error_player = 1;
	img->error_colec = 1;
	img->error_exit = 1;
	img->relative_path = "./img/dolphin.xpm";
	img->relative_path2 = "./img/parede.xpm";
	img->relative_path3 = "./img/sea.xpm";
	img->relative_path4 = "./img/fish.xpm";
	img->relative_path5 = "./img/shell.xpm";
	img->relative_path6 = "./img/open_shell.xpm";
	img->relative_path7 = "./img/hook.xpm";
	img->relative_path8 = "./img/dolphin2.xpm";
}

void	define_image_path(t_data *img)
{
	int		img_width;
	int		img_height;

	img->dolphin = mlx_xpm_file_to_image(img->mlx, img->relative_path,
			&img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(img->mlx, img->relative_path2,
			&img_width, &img_height);
	img->sea = mlx_xpm_file_to_image(img->mlx, img->relative_path3,
			&img_width, &img_height);
	img->fish = mlx_xpm_file_to_image(img->mlx, img->relative_path4,
			&img_width, &img_height);
	img->shell = mlx_xpm_file_to_image(img->mlx, img->relative_path5,
			&img_width, &img_height);
	img->open_shell = mlx_xpm_file_to_image(img->mlx, img->relative_path6,
			&img_width, &img_height);
	img->hook = mlx_xpm_file_to_image(img->mlx, img->relative_path7,
			&img_width, &img_height);
	img->dolphin2 = mlx_xpm_file_to_image(img->mlx, img->relative_path8,
			&img_width, &img_height);
}
