/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 15:28:42 by znichola         ###   ########.fr       */
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
						get_r(str_col) * (1 - prct) + get_r(end_col) *prct,
						get_g(str_col) * (1 - prct) + get_g(end_col) * prct,
						get_b(str_col) * (1 - prct) + get_b(end_col) * prct
						));
}

// 0.0    |---:---^---:-->| 1.0				^ = 3 - 2
//     [  :  ] [  :  ] [  :  ]				: = 3 - 1

// 0.0    |---:---^---:---^---:-->| 1.0 	^ = 4 - 2	chunk_offset -> colour_switch_boundry
//     [  :  ] [  :  ] [  :  ] [  :  ]		: = 4 - 1	chunk

int	colour_ramp(int min, int max, int point)
{
	static const int	count = 5;
	static const int	pallet[5] = {PASTEL, PINK, LIGHT_BLUE, DEEP_BLUE, BACKGROUND};
	// static int	pallet[3] = {PASTEL, PINK, LIGHT_BLUE};
	double		prct;
	double		chunk;
	double		col_p;
	int			col_i;

	// prct = (point - min) / (double)(max - min);
	// chunk = 1 / (double)(count - 1);
	// col_i = (int)(prct / (double)chunk);
	// col_p = prct - (col_i * chunk);

	// col_p = col_p / chunk;

	if (max - min)
		point = 0;
	else
		point = point % (max - min);
	prct = (point - min) / (double)(max - min);
	chunk = 1 / (double)(count - 1);
	col_i = (int)(prct / (double)chunk);
	col_p = (prct - (col_i * chunk)) / chunk;

	return(create_trgb(0,
			get_r(pallet[col_i]) * (1 - col_p) + get_r(pallet[col_i + 1]) * (col_p),
			get_g(pallet[col_i]) * (1 - col_p) + get_g(pallet[col_i + 1]) * (col_p),
			get_b(pallet[col_i]) * (1 - col_p) + get_b(pallet[col_i + 1]) * (col_p)
		));
}

// >>> [ round((x/10.)/(1/3.)+0.33) for x in range(1, 11)]
// [1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0]

// >>> [ round((x/10.)/(1/3.)+(1/3.)) for x in range(1, 11)]
// [1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0]
// >>> [ ((x/20.)/.25) for x in range(1, 21)]
// [0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0]
// [0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0]
