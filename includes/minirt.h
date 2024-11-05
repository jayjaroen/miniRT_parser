/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:51:33 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/05 21:27:25 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//MAC
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/includes/libft.h"
//Linux
// # include "../MLX42/include/MLX42/MLX42.h"
// # include "libft.h"
# include "struct.h"

# include <math.h>
# include <stdbool.h>
# include <fcntl.h>

# define BIG 1e10
# define EPSILON 1e-6

// parsing
bool check_file(char *str);
bool check_scene_valid(char *file_name, t_program *program);


// linked list
void	add_to_list(t_obj **listptr, t_obj *item);
void	free_list(t_obj **listptr);

// need to take t_program as a parameter to access light_list and object_list
t_obj	*make_sphere(double x, double y, double z, double radius);
t_obj	*make_plane(double a, double b, double c, double d);
t_obj	*make_light(double x, double y, double z, double r, double g, double b);
// make_cylinder

//utils
void	set_color(t_color *color, double r, double g, double b);
void	copy_color(t_color *dst, t_color *src);

// vector operations
t_vec3	vector_add(t_vec3 a, t_vec3 b);
t_vec3	vector_subtract(t_vec3 a, t_vec3 b);
t_vec3	vector_negate(t_vec3 a);
t_vec3	vector_scale(t_vec3 a, double k);
double	vector_dot(t_vec3 a, t_vec3 b);
t_vec3	vector_cross(t_vec3 a, t_vec3 b);
double	vector_len(t_vec3 a);
t_vec3	vector_normalize(t_vec3 a);

// do_ray_trace
void	shade(t_ray *ray, t_hit *hit, t_program *p);
void	trace(t_ray *ray, t_color *color, t_program *program);
void	do_ray_trace(t_program *program);
double	make_light_ray(t_light *lightptr, t_vec3 point, t_ray *ray);
t_color	get_light_color(t_light *lightptr, t_ray *ray, double distance, t_program *p);

// clean and quit
void	clean_up(t_program *program);
// void	handle_key(mlx_key_data_t keydata, void *param);
void	quit_program(void *param);

#endif