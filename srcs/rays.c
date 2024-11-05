/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:56:01 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/01 23:49:37 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// create a ray from the camera position through the display at curr_x, curr_y
void	make_ray(unsigned int curr_x, unsigned int curr_y, t_ray *ray, t_program *p)
{
	double	screen_x;
	double	screen_y;
	t_vec3	tempv1;
	t_vec3	tempv2;

	screen_x = (curr_x - (double)p->display_width / 2.0) / (double)p->display_width;
	screen_y = (((double)(p->display_height - 1) - curr_y) \
		- (double)p->display_height / 2.0) / (double)p->display_height;
	//printf("%f, %f\n",  screen_x, screen_y);
	//return ;
	tempv1 = vector_scale(p->camera->up, screen_y);
	tempv2 = vector_scale(p->camera->right, screen_x);

	ray->direction = vector_add(tempv1, tempv2);
	ray->direction = vector_add(p->camera->orientation, ray->direction);
	ray->direction = vector_normalize(ray->direction);

	ray->origin.x = p->camera->viewpoint.x;
	ray->origin.y = p->camera->viewpoint.y;
	ray->origin.z = p->camera->viewpoint.z;
}

void	find_min_obj(double min_hit, t_ray *ray, t_program *p)
{
	double	hit;
	t_obj	*objptr;

	objptr = p->object_list;
	while (objptr)
	{
		hit = objptr->intersect(objptr, ray);
		if (hit > EPSILON && hit < min_hit)
		{
			min_hit = hit;
			p->min_obj = objptr;
		}
		objptr = objptr->next;
	}
}

void	trace(t_ray *ray, t_color *color, t_program *program)
{
	double	min_hit;
	double	normal_direction;
	t_hit	hit;

	set_color(color, 0.0, 0.0, 0.0);
	min_hit = BIG;
	program->min_obj = NULL;
	find_min_obj(min_hit, ray, program);
	if (min_hit == BIG)
	{
		set_color(color, 0.0, 0.0, 0.0);
		return ;
	}
	hit.point.x = min_hit * ray->direction.x + ray->origin.x;
	hit.point.y = min_hit * ray->direction.y + ray->origin.y;
	hit.point.z = min_hit * ray->direction.z + ray->origin.z;
	hit.normal = program->min_obj->normal(program->min_obj, hit.point);
	normal_direction = vector_dot(hit.normal, ray->direction);
	if (normal_direction > 0.0)
		hit.normal = vector_negate(hit.normal);
	shade(ray, &hit, program);
	color = &(hit.color);
}

void	do_ray_trace(t_program *program)
{
	unsigned int	x;
	unsigned int	y;
	t_ray			ray;
	t_color			color;

	y = 0;
	while (y < program->display_height)
	{
		x = 0;
		while (x < program->display_width)
		{
			make_ray(x, y, &ray, program);
			trace(&ray, &color, program);
			// write_pixel_color(&color, x);
			x++;
		}
		y++;
	}
}
