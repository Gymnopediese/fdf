/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:45:43 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 22:26:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector	ft_normal(t_vector a, t_vector b, t_vector c)
{
	t_vector	l1;
	t_vector	l2;
	t_vector	normal;
	float		l;

	l1 = ft_vect(b.x - a.x, b.y - a.y, b.z - a.z);
	l2 = ft_vect(c.x - a.x, c.y - a.y, c.z - a.z);
	normal = ft_vect(l1.y * l2.z - l1.z * l2.y,
			l1.z * l2.x - l1.x * l2.z, l1.x * l2.y - l1.y * l2.x);
	l = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
	return (normal);
}

double	dotprod(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	m4mult(t_vector p, double m[4][4], int div)
{
	t_vector	r;

	r.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0];
	r.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1];
	r.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2];
	r.w = p.x * m[0][3] + p.y * m[1][3] + p.z * m[2][3] + m[3][3];
	if (r.w && div)
	{
		r.x /= r.w;
		r.y /= r.w;
		r.z /= r.w;
	}
	return (r);
}
