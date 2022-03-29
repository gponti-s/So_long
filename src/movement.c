/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:53:17 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/12 09:53:33 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->ptr[x])
	{
		y = 0;
		while (vars->ptr[x][y])
		{
			if (vars->ptr[x][y] == 'P')
				break ;
			y++;
		}
		if (vars->ptr[x][y] == 'P')
			break ;
		x++;
	}
	movement_check(keycode, vars, x, y);
	return (0);
}

void	movement_check(int keycode, t_data *vars, int x, int y)
{
	if ((keycode == 126 || keycode == 13) && (vars->ptr[x - 1][y] != '1')
		&& (vars->game_over == 0))
		game_rules_up(vars, x, y);
	if ((keycode == 125 || keycode == 1) && (vars->ptr[x + 1][y] != '1')
		&& (vars->game_over == 0))
		game_rules_down(vars, x, y);
	if ((keycode == 123 || keycode == 0) && (vars->ptr[x][y - 1] != '1')
		&& (vars->game_over == 0))
		game_rules_left(vars, x, y);
	if ((keycode == 124 || keycode == 2) && (vars->ptr[x][y + 1] != '1')
		&& (vars->game_over == 0))
		game_rules_right(vars, x, y);
}

int	my_close(int keycode, t_data *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	my_close_x(int keycode, t_data *vars)
{
	(void) keycode;
	(void) vars;
	exit(0);
	return (0);
}
