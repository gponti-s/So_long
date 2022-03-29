/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:49:00 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/12 09:49:19 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame_sea(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height_x)
	{
		x = 0;
		while (x < img->large_y)
		{
			render_image(img, x, y, img->ptr[y][x]);
			x++;
		}
		y++;
	}
	print_end(img);
	print_inf(img);
	return (0);
}

void	render_image(t_data *img, int x, int y, char image)
{
	mlx_put_image_to_window(img->mlx, img->win, img->sea,
		(x * SCALE), (y * SCALE));
	if (image == '1' && img->game_over == 0)
		mlx_put_image_to_window(img->mlx, img->win, img->wall,
			(x * SCALE), (y * SCALE));
	else if (image == 'C' && img->game_over == 0)
		mlx_put_image_to_window(img->mlx, img->win, img->fish,
			(x * SCALE), (y * SCALE));
	else if (image == 'E' && img->game_over == 0 && img->exit != 0)
		mlx_put_image_to_window(img->mlx, img->win, img->shell,
			(x * SCALE), (y * SCALE));
	else if (image == 'E' && img->game_over == 0 && img->exit == 0)
		mlx_put_image_to_window(img->mlx, img->win, img->open_shell,
			(x * SCALE), (y * SCALE));
	else if (image == 'P' && img->game_over == 0)
		render_image_dolphin(img, x, y);
	else if (image == 'T' && img->game_over == 0)
		mlx_put_image_to_window(img->mlx, img->win, img->hook,
			(x * SCALE), (y * SCALE));
	else if (img->game_over != 0)
		mlx_put_image_to_window(img->mlx, img->win, img->sea,
			(x * SCALE), (y * SCALE));
	else if (image != '0')
		error_handler_character(img);
}

void	render_image_dolphin(t_data *img, int x, int y)
{
	if (img->sprit == 1)
		mlx_put_image_to_window(img->mlx, img->win, img->dolphin2,
			(x * SCALE), (y * SCALE));
	else
		mlx_put_image_to_window(img->mlx, img->win, img->dolphin,
			(x * SCALE), (y * SCALE));
}

void	print_inf(t_data *img)
{
	char	*ptr;
	char	*ptr2;

	ptr = ft_itoa(img->count_mov);
	mlx_string_put(img->mlx, img->win, 0, 0,
		create_trgb(0, 128, 255, 0), "MOVEMENTS: ");
	mlx_string_put(img->mlx, img->win, 100, 0,
		create_trgb(0, 128, 255, 0), ptr);
	ptr2 = ft_itoa(img->score);
	mlx_string_put(img->mlx, img->win, 0, 25,
		create_trgb(0, 0, 255, 255), "SCORE: ");
	mlx_string_put(img->mlx, img->win, 60, 25,
		create_trgb(0, 0, 255, 255), ptr2);
	free(ptr);
	free(ptr2);
}

void	print_end(t_data *img)
{
	if (img->game_over == 1)
		mlx_string_put(img->mlx, img->win, (img->large) / 2, (img->height) / 2,
			create_trgb(0, 0, 255, 0), "YOU WIN!!");
	else if (img->game_over == 2)
		mlx_string_put(img->mlx, img->win, (img->large) / 2, (img->height) / 2,
			create_trgb(0, 255, 255, 0), "YOU LOSE!!");
	else if ((img->count_mov > 20 && (img->large_y) < 15)
		|| (img->count_mov > 90 && (img->large_y) > 15))
		img->game_over = 2;
}
