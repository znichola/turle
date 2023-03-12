/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:24:30 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 23:37:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTORS_H
# define FT_VECTORS_H

// basic type for all spacial numbers
typedef double	t_num;

// basic position in 3d space
typedef struct s_v3
{
	t_num	x;
	t_num	y;
	t_num	z;
}	t_v3;

t_num	v3_mag(t_v3 v);
t_v3	v3_norm(t_v3 v);
t_v3	v3_perp(t_v3 v);
t_num	v3_dot(t_v3 a, t_v3 b);
t_num	v3_cross(t_v3 a, t_v3 b);
t_v3	v3_vadd(t_v3 a, t_v3 b);
t_v3	v3_subtract(t_v3 a, t_v3 b);
t_v3	v3_multiply(t_v3 v, t_num s);
t_v3	v3_divide(t_v3 v, t_num s);

#endif
