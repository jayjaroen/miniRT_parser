/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:36:36 by nusamank          #+#    #+#             */
/*   Updated: 2024/10/30 20:44:07 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_dot(t_vec3 a, t_vec3 b)
{
	double	c;

	c = a.x * b.x + a.y * b.y * a.z * b.z;
	return (c);
}

t_vec3	vector_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.z;
	return (c);
}

// vector magnitude
double	vector_len(t_vec3 a)
{
	double	l;

	l = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (l);
}

// converting a vector into a unit vector.
// A unit vector is a vector that has the magnitude equal to 1.
t_vec3	vector_normalize(t_vec3 a)
{
	t_vec3	b;
	double	l;

	l = vector_len(a);
	b.x = a.x / l;
	b.y = a.y / l;
	b.z = a.z / l;
	return (b);
}
