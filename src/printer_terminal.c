/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_terminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:45:37 by gponti-s          #+#    #+#             */
/*   Updated: 2021/08/19 12:45:42 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_score(t_data *vars)
{
	vars->score++;
	vars->exit--;
	write(1, "Score: ", 7);
	ft_putnbr_fd(vars->score, 1);
	write(1, "\n", 2);
}

void	print_count_mov(t_data *vars)
{
	vars->count_mov++;
	write(1, "Movement: ", 11);
	ft_putnbr_fd(vars->count_mov, 1);
	write(1, "\n", 2);
}
