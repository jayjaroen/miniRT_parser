/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:37:58 by nusamank          #+#    #+#             */
/*   Updated: 2024/11/02 13:44:33 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	make_reflected_ray(t_ray *ray, t_hit *hit, t_ray *reflected_ray)
{
	double	k;

	k = vector_dot(ray->direction, hit->normal);
	k *= -2.0;
	reflected_ray->origin = hit->point;
	reflected_ray->direction.x = k * hit->normal.x + ray->direction.x;
	reflected_ray->direction.y = k * hit->normal.y + ray->direction.y;
	reflected_ray->direction.z = k * hit->normal.z + ray->direction.z;
}

static void	add_diffuse(t_ray light_ray, t_hit *hit, t_program *p)
{
	double	diffuse;

	diffuse = vector_dot(hit->normal, light_ray.direction);
	if (diffuse > 0.0 && p->min_obj->diffuse > 0.01)
	{
		diffuse = pow(diffuse, p->min_obj->brilliance) * p->min_obj->diffuse;
		hit->color.r += hit->light_color.r * p->min_obj->color.r * diffuse;
		hit->color.g += hit->light_color.g * p->min_obj->color.g * diffuse;
		hit->color.b += hit->light_color.b * p->min_obj->color.b * diffuse;
	}
}

static void	add_specular(t_ray reflected_ray, t_ray light_ray, \
	t_hit *hit, t_program *p)
{
	double	specular;

	specular = vector_dot(reflected_ray.direction, light_ray.direction);
	if (specular > 0.0 && p->min_obj->specular > 0.0)
	{
		specular *= p->min_obj->specular;
		hit->color.r += hit->light_color.r * specular;
		hit->color.g += hit->light_color.g * specular;
		hit->color.b += hit->light_color.b * specular;
	}
}

// hit->light_color = total light color
void	shade(t_ray *ray, t_hit *hit, t_program *p)
{
	t_ray	light_ray;
	t_ray	reflected_ray;
	t_light	*light_src;

	make_reflected_ray(ray, hit, &reflected_ray);
	hit->color.r = p->min_obj->color.r * p->ambient_ratio;
	hit->color.g = p->min_obj->color.g * p->ambient_ratio;
	hit->color.b = p->min_obj->color.b * p->ambient_ratio;
	light_src = p->light_list;
	while (light_src)
	{
		hit->distance = make_light_ray(light_src, hit->point, &light_ray);
		hit->light_color = \
			get_light_color(light_src, &light_ray, hit->distance, p);
		add_diffuse(light_ray, hit, p);
		add_specular(reflected_ray, light_ray, hit, p);
		light_src = light_src->next;
	}
}
