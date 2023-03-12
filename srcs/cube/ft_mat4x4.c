/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4x4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:16 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 14:00:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mat4x4.h"

t_mat4x4 init_mat4x4()
{
	t_mat4x4	ret;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ret.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ret);
}

void v3_multiply_matrix(t_v3 *i, t_v3 *o, t_mat4x4 *m)
{
	t_num	w;

	o->x = (i->x * m->m[0][0] + i->y * m->m[1][0] + i->z * m->m[2][0] + m->m[3][0]);
	o->y = (i->x * m->m[0][1] + i->y * m->m[1][1] + i->z * m->m[2][1] + m->m[3][1]);
	o->z = (i->x * m->m[0][2] + i->y * m->m[1][2] + i->z * m->m[2][2] + m->m[3][2]);
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];

	if (w != 0)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}
