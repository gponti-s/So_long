/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:49:27 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/13 10:49:45 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map( t_data *img, char *argv)
{
	img->fd = open(argv, O_RDONLY);
	img->ptr = malloc (sizeof(char *) * 90);
	while (get_next_line(img->fd, &img->ptr[img->x]))
		img->x++;
	img->ptr[img->x] = NULL;
	img->x = 0;
	while (img->ptr[img->x])
	{
		img->y = 0;
		while (img->ptr[img->x][img->y])
		{
			if (img->ptr[img->x][img->y] == 'C')
				img->exit++;
			img->y++;
		}
		if (img->x > 0)
		{
			if (img->z != img->y)
				img->error_retangle = 1;
		}
		img->z = img->y;
		img->x++;
	}
	scale(img);
	close(img->fd);
}

void	scale(t_data *img)
{
	img->height_x = img->x;
	img->large_y = img->y;
	img->height = SCALE * img->x;
	img->large = SCALE * img->y;
}
