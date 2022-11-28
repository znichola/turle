/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turtle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:44:35 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 14:24:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURTLE_H
# define TURTLE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // strerror perror
# include <unistd.h>
# include <math.h>
# include <stdlib.h> // malloc exit 

# include "mlx.h"

#include "colours.h"

# define WIDTH 1000
# define HIGHT 1000

# define PI 3.1415926535

/* data structure for holding image data*/
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_ipoint
{
	int	x;
	int	y;
}				t_ipoint;

typedef struct	s_fpoint
{
	double	x;
	double	y;
}				t_fpoint;

typedef struct	s_shapes
{
	t_fpoint	big_circle;
	t_fpoint	l_circle;
	t_fpoint	r_circle;
}				t_shapes;

typedef struct	s_app
{
	t_data		data;
	void		*mlx;
	void		*mlx_win;
	t_ipoint	mouse;
	t_ipoint	mouse_left;
	t_ipoint	mouse_right;
	t_ipoint	center;
	t_fpoint	scale;
	t_fpoint	offset;
	t_shapes	shapes;
}				t_app;



// drawring
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		put_square(t_data *data, int w, int h, int x, int y);
int			put_circle(t_data *d, int r, t_ipoint center, int colour);
// void	put_line(t_data *data, int x, int y, int x_, int y_);
void		put_line(t_data *d, t_ipoint p1, t_ipoint p2);
void		fill_screen(t_data *d, int colour);

// colours
int			colour_lerp(int min, int max, int point);

// init
// void	init_map(t_app *a);
void		pi(t_ipoint p);
void		pf(t_fpoint p);
void		world_to_screen(t_app *a, t_fpoint w, t_ipoint *s);
void		screen_to_world(t_app *a, t_ipoint s, t_fpoint *w);

// hooks
int			destroy(t_app *a);
int			key_press(int keycode, t_app *a);
int			mouse_hook(int action, int x, int y, t_app *a);
int			render_next_frame(t_app *a);

// map
void		init_map(t_app *a);
void		pi(t_ipoint p);		// uses printf
void		pf(t_fpoint p);		// uses printf
void		world_to_screen(t_app *a, t_fpoint w, t_ipoint *s);
void		screen_to_world(t_app *a, t_ipoint s, t_fpoint *w);
t_ipoint	rworld_to_screen(t_app *a, t_fpoint w);
t_fpoint	rscreen_to_world(t_app *a, t_ipoint s);

#endif