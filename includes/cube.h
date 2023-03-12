/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:24:17 by znichola          #+#    #+#             */
/*   Updated: 2023/03/12 02:17:32 by znichola         ###   ########.fr       */
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
# include "ft_mat4x4.h"

typedef	struct s_tris
{
	t_v3	a;
	t_v3	b;
	t_v3	c;
}	t_tris;


typedef	struct s_cude
{
	t_tris	mesh[12];
}	t_cube;

typedef struct s_mlx
{
	// mlx image display
	void		*instance;
	void		*win;
	t_data		image;

	//objects
	t_cube		*cube;

	// 3d projection
	t_mat4x4	*mat_proj;

	// world . screen
	t_ipoint	mouse;
	t_ipoint	mouse_left;
	t_ipoint	mouse_right;
	t_fpoint	scale;
	t_fpoint	offset;

	// controles
	int			mouse_input[6];
	int			mouse_hold[6];

	t_ipoint	mouse_atclick_pos[6];
}	t_mlx;

int			cube_render(t_mlx *app);
int			cube_destroy(t_mlx *app);

t_ipoint	cube_rworld_to_screen(t_mlx *a, t_fpoint w);
t_fpoint	cube_rscreen_to_world(t_mlx *a, t_ipoint s);

void		put_triangle(t_mlx *app, t_tris *t);
void		cube_put_line(t_mlx *app, t_fpoint pf1, t_fpoint pf2);

int			cube_mouse_hook(int action, int x, int y, t_mlx *a);
int			cube_mouse_release_hook(int action, int x, int y, t_mlx *a);

void		cube_zoom(t_mlx *a, int dir);

void		put_circle_fast(t_mlx *a, int r, t_fpoint c, int colour);

void	process_mouse_stuff(t_mlx *a);

#endif
