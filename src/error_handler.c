/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:54:45 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/20 13:54:48 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler_argc(int argc)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "erro\n", 6);
		write(1, "argument invalid\n", 17);
		exit(0);
	}
}

void	error_handler_map(t_data *vars)
{
	if (vars->error_retangle == 1)
	{
		write(1, "erro\n", 6);
		write(1, "map is not a retangle\n", 23);
		free_map(vars);
		exit(0);
	}
	if (error_handler_wall(vars) == 1)
	{
		write(1, "erro\n", 6);
		write(1, "There is no wall\n", 18);
		free_map(vars);
		exit(0);
	}
	if (vars->error_player == 1)
		error_handler_character(vars);
	if (vars->error_colec == 1)
		error_handler_character(vars);
	if (vars->error_exit == 1)
		error_handler_character(vars);
}

int	error_handler_wall(t_data *vars)
{
	int	j;
	int	i;

	j = 0;
	while (j < vars->height_x)
	{
		i = 0;
		while (i < vars->large_y)
		{
			if (vars->ptr[0][i] != '1' || vars->ptr[j][0] != '1'
			|| vars->ptr[vars->height_x - 1][i] != '1'
			|| vars->ptr[j][vars->large_y - 1] != '1')
				return (1);
			if (vars->ptr[j][i] == 'P')
				vars->error_player = 0;
			if (vars->ptr[j][i] == 'C')
				vars->error_colec = 0;
			if (vars->ptr[j][i] == 'E')
				vars->error_exit = 0;
			i++;
		}
		j++;
	}
	return (0);
}

int	error_handler_character(t_data *vars)
{
	(void)vars;
	write(1, "erro\n", 6);
	write(1, "invalid Character\n", 18);
	free_map(vars);
	exit(0);
}

void	free_map(t_data *vars)
{
	int	i;

	i = 0;
	if (vars->ptr)
	{
		while (vars->ptr[i])
		{
			free(vars->ptr[i]);
			i++;
		}
		free(vars->ptr);
	}
}
