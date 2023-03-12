/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4x4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:26:35 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 13:49:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAT4X4_H
# define FT_MAT4X4_H

#include <math.h>
#include "ft_vectors.h"

typedef struct s_mat4x4
{
	t_num	m[4][4];
}	t_mat4x4;

t_mat4x4	init_mat4x4();
void		v3_multiply_matrix(t_v3 *i, t_v3 *o, t_mat4x4 *m);

#endif
