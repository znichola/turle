/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:24:01 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 01:04:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	cube_render(t_mlx *app)
{
	put_circle(&app->image, 10, (t_ipoint){400, 400}, PASTEL);
	// my_mlx_pixel_put(&app->image, 5, 5, PINK);

	mlx_put_image_to_window(app->instance, app->win, app->image.img, 0, 0);
	return (0);
}

int	cube_destroy(t_mlx *app)
{
	mlx_destroy_window(app->instance, app->win);
	exit(0);
	return (0);
}
