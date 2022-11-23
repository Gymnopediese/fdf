/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:14:25 by albaud            #+#    #+#             */
/*   Updated: 2022/11/03 11:56:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define OFFSETS 5
void	handle_input2(int key, t_camera *cam)
{
	if (key == KEYCODE_F)
		cam->mode *= -1;
	else if (key == KEYCODE_K)
		cam->cback += 9;
	else if (key == KEYCODE_L)
		cam->cback += 1;
	else if (key == KEYCODE_I)
		cam->cgrad += 9;
	else if (key == KEYCODE_O)
		cam->cgrad += 1;
	cam->cgrad = cam->cgrad % 10;
	cam->cback = cam->cback % 10;
	ft_putnbrn(cam->cgrad);
	ft_putnbrn(cam->cback);
}

void	handle_input(int key, t_camera *cam)
{
	if (key == KEYCODE_W)
		cam->theta -= 0.1;
	else if (key == KEYCODE_S)
		cam->theta += 0.1;
	else if (key == KEYCODE_A)
		cam->beta += 0.1;
	else if (key == KEYCODE_D)
		cam->beta -= 0.1;
	else if (key == KEYCODE_SPACE)
		cam->fov -= 0.25;
	else if (key == KEYCODE_C)
		cam->fov += 0.25;
	else if (key == KEYCODE_LEFT_ARROW)
		cam->xoff += OFFSETS;
	else if (key == KEYCODE_RIGHT_ARROW)
		cam->xoff -= OFFSETS;
	else if (key == KEYCODE_UP_ARROW)
		cam->yoff += OFFSETS;
	else if (key == KEYCODE_DOWN_ARROW)
		cam->yoff -= OFFSETS;
	else if (key == 53)
		ft_garbage_colector(0, 1, 1);
	else
		handle_input2(key, cam);
}
