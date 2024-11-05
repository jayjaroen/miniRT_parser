/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:12:54 by nusamank          #+#    #+#             */
/*   Updated: 2024/10/27 09:46:34 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	sphere_intersect(t_obj *this, t_ray *ray)
{
	double	b;
	double	c;
	double	discrim;
	double	t0;
	double	t1;

	b = 2 * ((ray->direction.x * (ray->origin.x - this->u_objspec.sp.center.x)) \
		+ (ray->direction.y * (ray->origin.y - this->u_objspec.sp.center.y)) \
		+ (ray->direction.z * (ray->origin.z - this->u_objspec.sp.center.z)));
	c = pow((ray->origin.x - this->u_objspec.sp.center.x), 2) \
		+ pow((ray->origin.y - this->u_objspec.sp.center.y), 2) \
		+ pow((ray->origin.z - this->u_objspec.sp.center.z), 2) \
		- this->u_objspec.sp.radius2;
	discrim = pow(b, 2) - 4 * c;
	if (discrim <= EPSILON)
		return (0.0);
	discrim = sqrt(discrim);
	t0 = (-b - discrim) * 0.5;
	if (t0 > EPSILON)
		return (t0);
	t1 = (-b + discrim) * 0.5;
	if (t1 > EPSILON)
		return (t1);
	return (0.0);
}

t_vec3	sphere_normal(t_obj *this, t_vec3 point)
{
	t_vec3	normal;

	normal = vector_subtract(point, this->u_objspec.sp.center);
	normal = vector_normalize(normal);
	return (normal);
}
