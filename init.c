/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:47:37 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 23:29:34 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_zero(t_camera *cam)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			cam->m[i][j] = 0;
			cam->rotx[i][j] = 0;
			cam->rotz[i][j] = 0;
		}
	}
}

void	rot(t_camera *cam)
{
	cam->fovrad = 1 / tanf(ft_deg_to_rad(cam->fov / 2));

	cam->rotz[0][0] = 1;
	cam->rotz[1][1] = cosf(cam->theta);
	cam->rotz[1][2] = sinf(cam->theta);
	cam->rotz[2][1] = -sinf(cam->theta);
	cam->rotz[2][2] = cosf(cam->theta);
	cam->rotx[0][0] = cosf(cam->beta);
	cam->rotx[1][1] = 1;
	cam->rotx[0][2] = -sinf(cam->beta);
	cam->rotx[2][0] = sinf(cam->beta);
	cam->rotx[2][2] = cosf(cam->beta);


	// cam->rotz[0][0] = 1;
	// cam->rotz[0][1] = cosf(cam->theta);
	// cam->rotz[1][0] = sinf(cam->theta);
	// cam->rotz[1][1] = -sinf(cam->theta);
	// cam->rotz[2][2] = cosf(cam->theta);

	// cam->rotx[0][0] = 1;
	// cam->rotx[1][1] = cosf(cam->beta);
	// cam->rotx[1][2] = sinf(cam->beta);
	// cam->rotx[2][1] = -sinf(cam->beta);
	// cam->rotx[2][2] = cosf(cam->beta);

	cam->m[0][0] = cam->ration * cam->fovrad;
	cam->m[1][1] = cam->fovrad;
	cam->m[2][2] = (double)cam->far / (double)(cam->far - cam->near);
	cam->m[3][2] = (double)(-cam->far * cam->near) / (double)(cam->far - cam->near);
	printf("%f\n",cam->m[3][2]);
	cam->m[2][3] = 1;
	cam->m[3][3] = 0;
	// cam->m[0][0] = 0.1;
	// cam->m[1][1] = 0.1;
	// cam->m[2][2] = 1000.1;
	// cam->m[3][2] = 1;
	// printf("%f\n",cam->m[3][2]);
	// cam->m[2][3] = 1000 * 0.1;
	// cam->m[3][3] = 0;
}

void	gradient(t_camera *cam)
{
	gradient0(cam->gradients[0]);
	gradient1(cam->gradients[1]);
	gradient2(cam->gradients[2]);
	gradient3(cam->gradients[3]);
	gradient4(cam->gradients[4]);
	gradient5(cam->gradients[5]);
	gradient6(cam->gradients[6]);
	gradient7(cam->gradients[7]);
	gradient8(cam->gradients[8]);
	gradient9(cam->gradients[9]);
	cam->backgrounds[0] = BLACK;
	cam->backgrounds[1] = WHITE;
	cam->backgrounds[2] = RED;
	cam->backgrounds[3] = BLUE;
	cam->backgrounds[4] = GREEN;
	cam->backgrounds[5] = PINK;
	cam->backgrounds[6] = YELLOW;
	cam->backgrounds[7] = LIGHT_BLUE;
	cam->backgrounds[8] = 0x756d73;
	cam->backgrounds[9] = WHITE;
}

void	init_camera(t_camera *cam)
{
	cam->near = 0.1;
	cam->far = 1000;
	cam->fov = 90;
	cam->ration = (double)10 / (double)10;
	cam->theta = 0;
	cam->beta = 0;
	cam->yoff = 0;
	cam->xoff = 0;
	cam->mode = 1;
	cam->cback = 0;
	cam->cgrad = 0;
	cam->max = ft_intmmax(cam->map);
	cam->min = ft_intmmin(cam->map);
	gradient(cam);
	ft_zero(cam);
}
