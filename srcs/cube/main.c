/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:17:42 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 03:08:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

	t_cube	cube = {
		// south
		(t_tri){(t_v3){0, 0, 0}, (t_v3){0, 100, 0}, (t_v3){100, 100, 0}},
		(t_tri){(t_v3){0, 0, 0}, (t_v3){100, 100, 0}, (t_v3){100, 0, 0}},

		// east
		(t_tri){(t_v3){100, 0, 0}, (t_v3){100, 100, 0}, (t_v3){100, 100, 100}},
		(t_tri){(t_v3){100, 0, 0}, (t_v3){100, 100, 100}, (t_v3){100, 0, 100}},

		// north
		(t_tri){(t_v3){100, 0, 100}, (t_v3){100, 100, 100}, (t_v3){100, 100, 100}},
		(t_tri){(t_v3){100, 0, 100}, (t_v3){0, 100, 100}, (t_v3){0, 0, 100}},

		// west
		(t_tri){(t_v3){0, 0, 100}, (t_v3){0, 100, 100}, (t_v3){0, 100, 0}},
		(t_tri){(t_v3){0, 0, 100}, (t_v3){0, 100, 0}, (t_v3){0, 0, 0}},

		// top
		(t_tri){(t_v3){0, 100, 0}, (t_v3){0, 100, 100}, (t_v3){100, 100, 100}},
		(t_tri){(t_v3){0, 100, 0}, (t_v3){100, 100, 100}, (t_v3){100, 100, 0}},

		// bottom
		(t_tri){(t_v3){100, 0, 100}, (t_v3){0, 0, 100}, (t_v3){0, 0, 0}},
		(t_tri){(t_v3){100, 0, 100}, (t_v3){0, 0, 0}, (t_v3){100, 0, 0}}
		};
	app.cube = &cube;



	mlx_hook(app.win, ON_DESTROY, 0, cube_destroy, &app);

	mlx_loop_hook(app.instance, cube_render, &app);

	mlx_loop(app.instance);
	return (0);
}
