/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:24:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/13 18:47:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "math.h"

// magnetude is the scalar quantity of the vector
t_num	v3_mag(t_v3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// it is important the order of the points is consistent
// to always have the same normal
// going to the left or right
t_v3	v3_norm(t_v3 v)
{
	// do something
	return (v);
}

t_v3 v3_perp(t_v3 v)
{
	return (v);
}

// a scalar quantity
t_num v3_dot(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// a vector quantity
t_num v3_cross(t_v3 a, t_v3 b)
{
	return (a.x * b.x - a.y * b.y - a.z * b.z);
}

t_v3 v3_vadd(t_v3 a, t_v3 b)
{
	return ((t_v3){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_v3 v3_subtract(t_v3 a, t_v3 b)
{
	return ((t_v3){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_v3 v3_multiply(t_v3 v, t_num s)
{
	return ((t_v3){v.x * s, v.y * s, v.z * s});
}

t_v3 v3_divide(t_v3 v, t_num s)
{
	if (s == 0)
		return (v);
	return ((t_v3){v.x / s, v.y / s, v.z / s});
}
