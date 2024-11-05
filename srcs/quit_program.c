/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:18:32 by nusamank          #+#    #+#             */
/*   Updated: 2024/10/25 09:24:08 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_up(t_program *program)
{
	if (program->mlx)
		mlx_terminate(program->mlx);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_program	*program;

	program = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_program(program);
}

void	quit_program(void *param)
{
	t_program	*program;

	program = param;
	clean_up(program);
	exit(0);
}
