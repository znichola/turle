/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:58:58 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 14:24:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turtle.h"

void	init_map(t_app *a)
{
	a->mlx = mlx_init();
	a->mlx_win = mlx_new_window(a->mlx, WIDTH, HIGHT, "Turtle's paradise");
	a->data.img = mlx_new_image(a->mlx, WIDTH, HIGHT);
	a->data.addr = mlx_get_data_addr(a->data.img,
									&a->data.bits_per_pixel,
									&a->data.line_length,
									&a->data.endian);

	a->offset.x = 0.0;
	a->offset.y = 0.0;
	a->scale.x = 1;
	a->scale.y = 1;
}