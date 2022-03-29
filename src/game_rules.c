/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:34:28 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/18 09:34:48 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_rules_up(t_data *vars, int x, int y)
{
	if (vars->ptr[x - 1][y] == 'C')
		print_score(vars);
	if (vars->ptr[x - 1][y] == 'E')
	{
		if (vars->exit != 0)
			return ;
		vars->game_over = 1;
	}
	if (vars->ptr[x - 1][y] == 'T')
		vars->game_over = 2;
	vars->ptr[x - 1][y] = 'P';
	vars->ptr[x][y] = '0';
	print_count_mov(vars);
}

void	game_rules_down(t_data *vars, int x, int y)
{
	if (vars->ptr[x + 1][y] == 'C')
		print_score(vars);
	if (vars->ptr[x + 1][y] == 'E')
	{
		if (vars->exit != 0)
			return ;
		vars->game_over = 1;
	}
	if (vars->ptr[x + 1][y] == 'T')
		vars->game_over = 2;
	vars->ptr[x + 1][y] = 'P';
	vars->ptr[x][y] = '0';
	print_count_mov(vars);
}

void	game_rules_left(t_data *vars, int x, int y)
{
	if (vars->ptr[x][y - 1] == 'C')
		print_score(vars);
	if (vars->ptr[x][y - 1] == 'E')
	{
		if (vars->exit != 0)
			return ;
		vars->game_over = 1;
	}
	if (vars->ptr[x][y - 1] == 'T')
		vars->game_over = 2;
	vars->ptr[x][y - 1] = 'P';
	vars->ptr[x][y] = '0';
	print_count_mov(vars);
	vars->sprit = 1;
}

void	game_rules_right(t_data *vars, int x, int y)
{
	if (vars->ptr[x][y + 1] == 'C')
		print_score(vars);
	if (vars->ptr[x][y + 1] == 'E')
	{
		if (vars->exit != 0)
			return ;
		vars->game_over = 1;
	}
	if (vars->ptr[x][y + 1] == 'T')
		vars->game_over = 2;
	vars->ptr[x][y + 1] = 'P';
	vars->ptr[x][y] = '0';
	print_count_mov(vars);
	vars->sprit = 0;
}
