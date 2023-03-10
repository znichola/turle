/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:07:39 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 22:40:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turtle.h"

// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || y < 0 || x > data->width || y > data->hight)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	fill_screen(t_data *d, int colour)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < d->width * d->hight * 4)
		d->addr[i++] = (unsigned int)colour;
}

void	put_square(t_data *data, int w, int h, int x, int y)
{
	for (int i = x; i < x+w; i++)
	{
		for (int e = y; e < y+h; e++)
			my_mlx_pixel_put(data, i, e, 0x00FF0000);
	}
}

// https://www.youtube.com/watch?v=bfvmPa9eWew
void	put_line(t_data *d, t_ipoint p1, t_ipoint p2)
{
	int	rise;
	int	run;
	int	t;
	int	i;
	double	m;
	double	b;
	
	rise = p2.y - p1.y;
	run = p2.x - p1.x;

	// printf("(%d, %d) -> (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	// printf("rise=%d\nrun=%d\n", rise, run);
	if (run == 0)
	{
		if (p2.y < p1.y)
		{
			t = p1.y;
			p1.y = p2.y;
			p2.y = t;
		}
		i = p1.y;
		while (i <= p2.y)
		{
			my_mlx_pixel_put(d, (int)((i - b) / m), i,
								colour_ramp(p1.y, p2.y, i));
			i++;
		}
	}
	else
	{
		m = (double)rise / run;
		b = (double)p1.y - m * p1.x;
		// printf("m= %f = %d / %d\nb=%f = %d - %f * %d\n", m, rise, run, b, p1.y, m, p1.x);
		if (m <= 1 && m >= -1)
		{
			if (p2.x < p1.x)
			{
				t = p1.x;
				p1.x = p2.x;
				p2.x = t;
			}
			i = p1.x;
			while (i <= p2.x)
			{
				my_mlx_pixel_put(d, i, (int)(m * i + b),
								colour_ramp(p1.x, p2.x, i));
				i++;
			}
		}
		else
		{
			if (p2.y < p1.y)
			{
				t = p1.y;
				p1.y = p2.y;
				p2.y = t;
			}
			i = p1.y;
			while (i <= p2.y)
			{
				my_mlx_pixel_put(d, (int)((i - b) / m), i,
								colour_ramp(p1.y, p2.y, i));
				i++;
			}
			
		}
	}
}

int	put_circle(t_data *d, int r, t_ipoint center, int colour)
{
	double		angle;
	t_fpoint	q;

	angle = 0.0;
	while(angle < 360)
	{
		q.x = r * cos(angle * PI / 180);
		q.y = r * sin(angle * PI / 180);
		my_mlx_pixel_put(d, q.x + center.x, q.y + center.y, colour);
		angle += 0.1;
	}
	return (1);
}