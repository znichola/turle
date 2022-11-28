/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 10:00:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turtle.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

// linear interpolatoin
// when there are more than one pixel colour
// coord == 7.8 gives us 0.3 which 
// indicates we are 30% of the way to pixel 8.0's center
// double left_center = floor(coord - 0.5) + 0.5;
// double dist = coord - left_center;
// samll optimisation to remove an extra +0.5 calculation
// double adjusted_coord = coord - 0.5;
// double dist = adjusted_coord - floor(adjusted_coord);
// double right_ratio = dist;
// double left_ratio = 1 - dist;
// // red channel value of 30 for start pixel
// // 						150 for end pixel
// int left_red = 30;// red channel value of the pixel to the left
// int right_red = 150;// red channel value of the pixel to the right
// int red = left_red * left_ratio + right_red * right_ratio;
// https://www.youtube.com/watch?v=IDFB5CDpLDE
int	colour_lerp(int min, int max, int point)
{
	int	str_col;
	int	end_col;

	str_col = LIGHT_BLUE;
	end_col = PASTEL;
	
	double	prct;
	prct = (double)(point - min) / (max - min);
	return(create_trgb(0,
						get_r(str_col) * (1 - prct) + get_r(end_col) * prct,
						get_g(str_col) * (1 - prct) + get_g(end_col) * prct,
						get_b(str_col) * (1 - prct) + get_b(end_col) * prct
						));
}