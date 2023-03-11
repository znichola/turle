/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:24:17 by znichola          #+#    #+#             */
/*   Updated: 2023/03/11 00:52:59 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "mlx.h"
# include "colours.h"
# include "defines.h"
# include "controls.h"
# include "turtle.h"

typedef	struct s_mlx
{
	void	*instance;
	void	*win;
	t_data	image;
}	t_mlx;

int	cube_render(t_mlx *app);
int	cube_destroy(t_mlx *app);

#endif
