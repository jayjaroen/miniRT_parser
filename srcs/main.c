/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:25:33 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/05 21:41:46 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include "../includes/minirt.h"
int	main(int argc, char **argv)
{
	t_program	program;

	ft_bzero(&program, sizeof(t_program));
	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	//parsing
	// check file if it's in the right form
	printf("file : %s\n", argv[1]);
	if (!check_file(argv[1]))
		return (1);
	// to check the arguments is valid: based on object && requirement
	// init_scene(&program, argv[1]);

	// program.display_width = 400;
	// program.display_height = 300;
	// program.mlx = mlx_init(program.display_width, program.display_height, "miniRT", true);
	// //if (!program.mlx)
	// 	//handle_error(&program, "Unable to initialize mlx.\n");

	// do_ray_trace(&program);

	// mlx_key_hook(program.mlx, handle_key, &program);
	// mlx_close_hook(program.mlx, quit_program, &program);
	// mlx_loop(program.mlx);
}
