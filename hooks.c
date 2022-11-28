/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:09:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 14:52:07 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turtle.h"

int	destroy(t_app *a)
{
	mlx_destroy_window(a->mlx, a->mlx_win);
	exit(0);
	return (0);
}

void	zoom(t_app *a, int dir)
{
	t_fpoint	mouse_world_before_zoom;
	t_fpoint	mouse_world_after_zoom;
	
	printf("\n\nZOOM\n"); 
	printf("mouse: "); pi(a->mouse); printf("\n");

	mouse_world_before_zoom = rscreen_to_world(a, a->mouse);
	printf("world_mouse before zoom: "); pf(mouse_world_before_zoom); printf("\n");
	if (dir > 0)
	{
		a->scale.x *= 1.1;
		a->scale.y *= 1.1;
	}
	else if (dir < 0)
	{
		a->scale.x *= 0.9;
		a->scale.y *= 0.9;
	}
	else
	{
		return ;
	}
	mouse_world_after_zoom = rscreen_to_world(a, a->mouse);
	printf("world_mouse after zoom: "); pf(mouse_world_after_zoom); printf("\n");

	a->offset.x += (mouse_world_before_zoom.x - mouse_world_after_zoom.x);
	a->offset.y += (mouse_world_before_zoom.y - mouse_world_after_zoom.y);
}

int	key_press(int keycode, t_app *a)
{
	printf("\nkeycode:[%d]\n", keycode);
	if (keycode == 53)
		destroy(a);
	else if (keycode == 126 || keycode == 13)
		a->offset.y += 10;
	else if (keycode == 125 || keycode == 1)
		a->offset.y -= 10;
	else if (keycode == 124 || keycode == 2)
		a->offset.x -= 10;
	else if (keycode == 123 || keycode == 0)
		a->offset.x += 10;
	else if (keycode == 69)
	{
		zoom(a, 1);
		// a->scale.x *= 1.1;
		// a->scale.y *= 1.1;
	}
	else if (keycode == 78)
	{
		// a->scale.x *= 0.9;
		// a->scale.y *= 0.9;
		zoom(a, -1);
	}
	printf("offset: "); pf(a->offset); printf("\n");
	return (1);
}

int	mouse_hook(int action, int x, int y, t_app *a)
{
	a->mouse.x = x;
	a->mouse.y = y;
	// (void)a;
	if (action == 1)
	{
		printf("left click\n");
		a->mouse_left.x = x;
		a->mouse_left.y = y;
		a->shapes.l_circle = rscreen_to_world(a, a->mouse_left);
		printf("mouse position (%d, %d)\n", a->mouse_left.x, a->mouse_left.y);
	}
	else if (action == 2)
	{
		printf("right click\n");
		a->mouse_right.x = x;
		a->mouse_right.y = y;
		a->shapes.r_circle = rscreen_to_world(a, a->mouse_right);
		printf("mouse position (%d, %d)\n", a->mouse_right.x, a->mouse_right.y);
		
	}
	else if (action == 3)
		printf("middle click\n");
	else if (action == 4)
	{
		zoom(a, -1);
		// a->scale.x *= 0.9;
		// a->scale.y *= 0.9;
		printf("scroll up\n");
	}
	else if (action == 5)
	{
		zoom(a, 1);
		// a->scale.x *= 1.1;
		// a->scale.y *= 1.1;
		printf("scrpll down\n");
	}
	// else if (action == 6)
	// 	printf("action 6\n");
	return (0);
}

int	render_next_frame(t_app *a)
{
	// static t_shapes	shapes;
	// TODO maybe it's less efficient to destory 
	// and remake a new image, better to just overwrite the background
	// mlx_destroy_image(a->mlx,a->data.img);
	// a->data.img = mlx_new_image(a->mlx, WIDTH, HIGHT);
	fill_screen(&a->data, BACKGROUND);

	// ...now get the location of the cursor in world space again - It will have changed
	// because the scale has changed, but we can offset our world now to fix the zoom
	// location in screen space, because we know how much it changed laterally between
	// the two spatial scales. Neat huh? ;-)




	// float fMouseWorldX_AfterZoom, fMouseWorldY_AfterZoom;
	// ScreenToWorld(fMouseX, fMouseY, fMouseWorldX_AfterZoom, fMouseWorldY_AfterZoom);		
	// fOffsetX += (fMouseWorldX_BeforeZoom - fMouseWorldX_AfterZoom);
	// fOffsetY += (fMouseWorldY_BeforeZoom - fMouseWorldY_AfterZoom);

	put_circle(&a->data, ((HIGHT/2)-1) * a->scale.x, rworld_to_screen(a, a->shapes.big_circle), DEEP_BLUE);
	put_circle(&a->data, 10*a->scale.x, rworld_to_screen(a, a->shapes.l_circle), PASTEL);
	put_circle(&a->data, 10*a->scale.y, rworld_to_screen(a, a->shapes.r_circle), LIGHT_BLUE);
	put_line(&a->data, rworld_to_screen(a, a->shapes.l_circle), rworld_to_screen(a, a->shapes.r_circle));
	
	mlx_put_image_to_window(a->mlx, a->mlx_win, a->data.img, 0, 0);
	return (0);
}