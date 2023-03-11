/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:24:17 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 03:07:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "mlx.h"
# include "colours.h"
# include "defines.h"
# include "controls.h"
# include "turtle.h"
# include "ft_vectors.h"

typedef	struct s_triangle
{
	t_v3	a;
	t_v3	b;
	t_v3	c;
}	t_tri;


typedef	struct s_cude
{
	t_tri	mesh[12];
}	t_cube;

typedef struct s_mlx
{
	void	*instance;
	void	*win;
	t_data	image;
	t_cube	*cube;
}	t_mlx;

int	cube_render(t_mlx *app);
int	cube_destroy(t_mlx *app);

#endif
