/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:21:30 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/02 13:45:45 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// create a ray from the point of intersection to this light source
double	make_light_ray(t_light *lightptr, t_vec3 point, t_ray *ray)
{
	double	distance_t;

	ray->origin = point;
	ray->direction = vector_subtract(lightptr->center, point);
	distance_t = vector_len(ray->direction);
	ray->direction = vector_normalize(ray->direction);
	return (distance_t);
}

t_color	get_light_color(t_light *lightptr, t_ray *ray, double distance, t_program *p)
{
	t_obj		*shadow_objptr;
	t_color		color;
	double		distance_t;

	set_color(&color, 0.0, 0.0, 0.0);
	shadow_objptr = p->object_list;
	while (shadow_objptr)
	{
		if (shadow_objptr != p->min_obj)
		{
			distance_t = shadow_objptr->intersect(shadow_objptr, ray);
			if (distance_t > EPSILON && distance_t < distance)
				return (color);
		}
		shadow_objptr = shadow_objptr->next;
	}
	color.r = lightptr->color.r * lightptr->brightness;
	color.g = lightptr->color.g * lightptr->brightness;
	color.b = lightptr->color.b * lightptr->brightness;
	return (color);
}
