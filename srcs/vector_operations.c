/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:13:16 by nusamank          #+#    #+#             */
/*   Updated: 2024/10/26 14:56:16 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vector_add(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec3	vector_subtract(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec3	vector_negate(t_vec3 a)
{
	t_vec3	b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	return (b);
}

t_vec3	vector_scale(t_vec3 a, double k)
{
	t_vec3	b;

	b.x = a.x * k;
	b.y = a.y * k;
	b.z = a.z * k;
	return (b);
}
