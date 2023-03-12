/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:24:01 by znichola          #+#    #+#             */
/*   Updated: 2023/03/12 02:38:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "string.h" // for memset();

int	cube_render(t_mlx *app)
{
	fill_screen(&app->image, BACKGROUND);
	put_circle(&app->image, 10, (t_ipoint){400, 400}, PASTEL);
	// my_mlx_pixel_put(&app->image, 5, 5, PINK);
	// put_triangle(app, (t_tris){(t_v3){cube_rworld_to_screen()}})

	process_mouse_stuff(app);

	for (int i = 0; i < 12; i++)
	{
		t_tris	*input;
		t_tris	tri_projected;
		t_tris	tri_translated;

		input = &app->cube->mesh[i];
		tri_translated = *input;
		tri_translated.a.z = input->a.z + 600;
		tri_translated.b.z = input->b.z + 600;
		tri_translated.c.z = input->c.z + 600;

		input = &tri_translated;

		v3_multiply_matrix(&input->a, &tri_projected.a, app->mat_proj);
		v3_multiply_matrix(&input->b, &tri_projected.b, app->mat_proj);
		v3_multiply_matrix(&input->c, &tri_projected.c, app->mat_proj);
		put_triangle(app, &tri_projected);
		// break ;
	}

	mlx_put_image_to_window(app->instance, app->win, app->image.img, 0, 0);
	memset(&app->mouse_input, 0, sizeof(app->mouse_input));
	return (0);
}

int	cube_destroy(t_mlx *app)
{
	mlx_destroy_window(app->instance, app->win);
	exit(0);
	return (0);
}

void	put_triangle(t_mlx *app, t_tris *t)
{
	put_circle_fast(app, 4, (t_fpoint){t->a.x, t->a.y}, PASTEL);
	put_circle_fast(app, 4, (t_fpoint){t->b.x, t->b.y}, PASTEL);
	put_circle_fast(app, 4, (t_fpoint){t->c.x, t->c.y}, PASTEL);
	cube_put_line(app, (t_fpoint){t->a.x, t->a.y}, (t_fpoint){t->b.x, t->b.y});
	cube_put_line(app, (t_fpoint){t->b.x, t->b.y}, (t_fpoint){t->c.x, t->c.y});
	cube_put_line(app, (t_fpoint){t->c.x, t->c.y}, (t_fpoint){t->a.x, t->a.y});
}

// Convert coordinates from World Space --> Screen Space
t_ipoint	cube_rworld_to_screen(t_mlx *a, t_fpoint w)
{
	t_ipoint	s;

	s.x = (int)((w.x - a->offset.x) * a->scale.x);
	s.y = (int)((w.y - a->offset.y) * a->scale.y);
	// printf("offset: "); pf(a->offset); printf(" scale: "); pf(a->scale); printf("\n");
	// printf("world to screeen: "); pf(w); printf(" -> "); pi(s); printf("\n");
	return (s);
}

// Convert coordinates from Screen Space --> World Space
t_fpoint	cube_rscreen_to_world(t_mlx *a, t_ipoint s)
{
	t_fpoint	w;

	w.x = (float)(((float)s.x / a->scale.x) + a->offset.x);
	w.y = (float)(((float)s.y / a->scale.y) + a->offset.y);
	// printf("offset: "); pf(a->offset); printf(" scale: "); pf(a->scale); printf("\n");
	// printf("screen to world: "); pi(s); printf(" -> "); pf(w); printf("\n");
	return (w);
}

// https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
void	cube_put_line(t_mlx *app, t_fpoint pf1, t_fpoint pf2)
{
	t_ipoint p1;
	t_ipoint p2;

	p1 = cube_rworld_to_screen(app, pf1);
	p2 = cube_rworld_to_screen(app, pf2);

	int	dx = abs(p2.x - p1.x);
	int	dy = abs(p2.y - p1.y);

	int	sx = p1.x < p2.x ? 1 : -1;
	int	sy = p1.y < p2.y ? 1 : -1;

	int	err = (dx > dy ? dx : -dy) / 2;
	int	e2;

	while (1)
	{
		my_mlx_pixel_put(&app->image, p1.x, p1.y, PASTEL);
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

int	cube_mouse_hook(int action, int x, int y, t_mlx *a)
{
	a->mouse.x = x;
	a->mouse.y = y;
	if (action < 6 && action >= 0)
	{
		a->mouse_input[action] = 1;
		if (a->mouse_hold[action] == 0)
			a->mouse_atclick_pos[action] = (t_ipoint){x, y};
		a->mouse_hold[action] = 1;
	}
	if (action == MOUSE_LEFT)
	{
		printf("left click\n");
		if (a->mouse_input[action])
			printf("old pos: (%d, %d)\n", a->mouse_atclick_pos[action].x, a->mouse_atclick_pos[action].x);
	}
	else if (action == MOUSE_RIGHT)
	{
		printf("right click\n");
	}
	else if (action == MOUSE_MIDDLE)
		printf("middle click\n");
	else if (action == MOUSE_SCROLL_UP)
		cube_zoom(a, -1);
	else if (action == MOUSE_SCROLL_DOWN)
		cube_zoom(a, 1);
	return (0);
}

// https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html
int	cube_mouse_release_hook(int action, int x, int y, t_mlx *a)
{
	a->mouse = (t_ipoint){x, y};
	printf("motion detected!\n");
	if (action < 6 && action >= 0)
	{
		a->mouse_hold[action] = 0;
		a->mouse_atclick_pos[action] = (t_ipoint){0, 0};
		printf("release action %d\n", action);
	}
	return (0);
}

// ...now get the location of the cursor in world space again - It will have changed
// because the scale has changed, but we can offset our world now to fix the zoom
// location in screen space, because we know how much it changed laterally between
// the two spatial scales. Neat huh? ;-)
void	cube_zoom(t_mlx *a, int dir)
{
	t_fpoint	mouse_world_before_zoom;
	t_fpoint	mouse_world_after_zoom;

	mouse_world_before_zoom = cube_rscreen_to_world(a, a->mouse);
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
		return ;
	mouse_world_after_zoom = cube_rscreen_to_world(a, a->mouse);
	a->offset.x += (mouse_world_before_zoom.x - mouse_world_after_zoom.x);
	a->offset.y += (mouse_world_before_zoom.y - mouse_world_after_zoom.y);
}

// fast aproximative algo from stackoverflow
void	put_circle_fast(t_mlx *a, int r, t_fpoint c, int colour)
{
	int			y;
	int			x;
	t_ipoint	center;

	center = cube_rworld_to_screen(a, c);
	// r = r * 0.5 * a->scale.x;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(&a->image, center.x + x, center.y + y, colour);
			x++;
		}
		y++;
	}
}

void	process_mouse_stuff(t_mlx *a)
{
	if (a->mouse_input[MOUSE_LEFT] == 0 && a->mouse_hold[MOUSE_LEFT] == 1)
	{
		// if (a->mouse_atclick_pos->x != a->mouse.x
		// 	&& a->mouse_atclick_pos->y != a->mouse.y)
			printf("mouse (%d, %d) atClick (%d, %d) ", a->mouse.x, a->mouse.y, a->mouse_atclick_pos->x, a->mouse_atclick_pos->y);
	}
}
