/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:54:33 by nusamank          #+#    #+#             */
/*   Updated: 2024/10/31 11:38:01 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	plane_intersect(t_obj *this, t_ray *ray)
{
	double	vd;
	double	vo;
	double	t;

	vd = vector_dot(this->u_objspec.pl.normal, ray->direction);
	if (vd <= EPSILON)
		return (0.0);
	vo = vector_dot(this->u_objspec.pl.normal, ray->origin);
	vo += this->u_objspec.pl.distance;
	vo += -1.0;
	t = vo / vd;
	if (t < 0.0)
		return (0.0);
	return (t);
}

// t_vec3	plane_normal(t_obj *this, t_vec3 point)
// {
// 	t_vec3	normal;

// 	normal.x = this->u_objspec.pl.normal.x;
// 	normal.y = this->u_objspec.pl.normal.y;
// 	normal.z = this->u_objspec.pl.normal.z;
// 	return (normal);
// }
