/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:26:13 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/05 15:15:04 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{//convert RGB values from the range 0-255 to the range 0.0-1.0
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_hit
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
	t_color	light_color;
	double	specular;
	double	distance;
}	t_hit;

typedef struct s_camera
{
	t_vec3	viewpoint;
	t_vec3	orientation;
	int		fov; //the angle between the left and right edges of the camera's view.
	t_vec3	up;
	t_vec3	right;
}	t_camera;

typedef struct s_light
{
	t_vec3			center;
	double			brightness;
	t_color			color; //set white in mandatory
	struct s_light	*next; //bonus
}	t_light;

typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	double	radius2; // pow(radius,2)
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	double	distance;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
}	t_cylinder;

typedef struct s_object
{
	t_type			type;
	struct s_object	*next;
	t_color			color;
	double			diffuse;
	double			brilliance;
	double			specular;
	//double			roughness;
	// function pointers
	double			(*intersect)(struct s_object *, t_ray *);
	t_vec3			(*normal)(struct s_object *, t_vec3);
	//void			(*print_object)(struct s_object *);
	union
	{
		t_sphere	sp;
		t_plane		pl;
		t_cylinder	cy;
	}	u_objspec;
}	t_obj;

typedef struct s_program
{
	// mlx_t		*mlx;
	double		display_width;
	double		display_height;
	double		ambient_ratio;
	t_color		ambient_color;
	t_camera	*camera;
	t_light		*light_list;
	t_obj		*object_list;
	t_obj		*min_obj;
}	t_program;

#endif