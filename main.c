/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:44:17 by znichola          #+#    #+#             */
/*   Updated: 2022/12/14 13:03:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turtle.h"


int	main(void)
{
	t_app	a;
	
	init_map(&a);
	
	// mlx_hook(a.mlx, ON_RESIZE, 0, on_resise, &a);


	// put_circle(&img, 100, WIDTH/2, HIGHT/2);
	// fill_screen(&a.data, BACKGROUND);
	// put_circle(&a.data, (HIGHT/2)-1, WIDTH/2, HIGHT/2, DEEP_BLUE);
	// put_line(&img, (HIGHT/2), (WIDTH/2), 500, 500);
	// mlx_put_image_to_window(a.mlx, a.mlx_win, a.data.img, 0, 0);

	a.center.x = (400);
	a.center.y = (400);
	a.mouse_left.x	= 400;
	a.mouse_left.y = 200;
	// put_line(&a.img, a.center, a.mouse);
	
	a.shapes.big_circle = rscreen_to_world(&a, a.center);
	a.shapes.l_circle = rscreen_to_world(&a, a.mouse_left);
	a.shapes.r_circle = rscreen_to_world(&a, a.mouse_right);

	mlx_mouse_hook(a.mlx_win, mouse_hook, &a);
	mlx_key_hook(a.mlx_win, key_press, &a);
	
	mlx_hook(a.mlx_win, ON_DESTROY, 0, destroy, &a);

	// mlx_hook(a.mlx_win, ON_MOUSEDOWN, 0, mouse_hold, &a);

	mlx_loop_hook(a.mlx, render_next_frame, &a);

	mlx_loop(a.mlx);
	return (0);
}