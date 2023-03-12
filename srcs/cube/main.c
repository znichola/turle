/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:17:42 by znichola          #+#    #+#             */
/*   Updated: 2023/03/12 02:34:22 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "string.h" // used for memset();

int	main(void)
{
	t_mlx	app;

	app.instance = mlx_init();
	app.image.width = WIDTH;
	app.image.hight = HIGHT;

	app.win = mlx_new_window(app.instance, app.image.width, app.image.hight, "Cubes abound");
	app.image.img = mlx_new_image(app.instance, app.image.width, app.image.hight);
	app.image.addr = mlx_get_data_addr(app.image.img,
									&app.image.bits_per_pixel,
									&app.image.line_length,
									&app.image.endian);

// https://www.youtube.com/watch?v=ih20l3pJoeU
	t_cube	cube = {
		// south
		(t_tris){(t_v3){0, 0, 0}, (t_v3){0, 100, 0}, (t_v3){100, 100, 0}},
		(t_tris){(t_v3){0, 0, 0}, (t_v3){100, 100, 0}, (t_v3){100, 0, 0}},

		// east
		(t_tris){(t_v3){100, 0, 0}, (t_v3){100, 100, 0}, (t_v3){100, 100, 100}},
		(t_tris){(t_v3){100, 0, 0}, (t_v3){100, 100, 100}, (t_v3){100, 0, 100}},

		// north
		(t_tris){(t_v3){100, 0, 100}, (t_v3){100, 100, 100}, (t_v3){0, 100, 100}},
		(t_tris){(t_v3){100, 0, 100}, (t_v3){0, 100, 100}, (t_v3){0, 0, 100}},

		// west
		(t_tris){(t_v3){0, 0, 100}, (t_v3){0, 100, 100}, (t_v3){0, 100, 0}},
		(t_tris){(t_v3){0, 0, 100}, (t_v3){0, 100, 0}, (t_v3){0, 0, 0}},

		// top
		(t_tris){(t_v3){0, 100, 0}, (t_v3){0, 100, 100}, (t_v3){100, 100, 100}},
		(t_tris){(t_v3){0, 100, 0}, (t_v3){100, 100, 100}, (t_v3){100, 100, 0}},

		// bottom
		(t_tris){(t_v3){100, 0, 100}, (t_v3){0, 0, 100}, (t_v3){0, 0, 0}},
		(t_tris){(t_v3){100, 0, 100}, (t_v3){0, 0, 0}, (t_v3){100, 0, 0}}
		};

	// projection matrix
	t_num	f_near = 0.1;
	t_num	f_far = 1000.0;
	t_num	f_fov = 90.0;
	t_num	f_aspect_ratio = app.image.width / app.image.hight;
	t_num	f_fov_rad = 1.0 / tan(f_fov * 0.5 / 180 * PI);

	t_mat4x4	mat_proj;

	mat_proj = init_mat4x4();

	mat_proj.m[0][0] = f_aspect_ratio * f_fov_rad;
	mat_proj.m[1][1] = f_fov_rad;
	mat_proj.m[2][2] = f_far / (f_far - f_near);
	mat_proj.m[3][2] = (-f_far * f_near) / (f_far - f_near);
	mat_proj.m[2][3] = 1.0;
	mat_proj.m[3][3] = 0.0;

	app.offset = (t_fpoint){0, 0};
	app.scale = (t_fpoint){1.0, 1.0};
	app.mouse = (t_ipoint){0, 0};
	app.mouse_left = (t_ipoint){0, 0};
	app.mouse_right = (t_ipoint){0, 0};


	app.cube = &cube;
	app.mat_proj = & mat_proj;

	memset(&app.mouse_input, 0, sizeof(app.mouse_input));
	memset(&app.mouse_hold, 0, sizeof(app.mouse_hold));
	memset(&app.mouse_atclick_pos, 0, sizeof(app.mouse_atclick_pos));

	mlx_hook(app.win, ON_DESTROY, 0, cube_destroy, &app);
	// mlx_hook(app.win, ButtonRelease, ButtonReleaseMask, );
	mlx_hook(app.win, 5, (1L<<3) | (1L<<13), cube_mouse_release_hook, &app);
	mlx_mouse_hook(app.win, cube_mouse_hook, &app);

	mlx_loop_hook(app.instance, cube_render, &app);

	mlx_loop(app.instance);
	return (0);
}
