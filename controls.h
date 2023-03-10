/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:28:14 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 23:40:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# ifdef __linux__
enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_LEAVE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25,
};

enum e_mouse_key
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	MOUSE_MIDDLE = 2,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
};

enum e_key {
	KEY_ESC = 65307,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_SPACE = 32,
	KEY_J = 106,
	KEY_M = 109,
	KEY_B = 110,
	KEY_N = 98,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_0 = 48,
};
#else
enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_LEAVE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25,
};

enum e_mouse_key
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
};

enum e_key {
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
};
# endif /* linux check */

#endif
