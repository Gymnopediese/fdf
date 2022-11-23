/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:54:28 by albaud            #+#    #+#             */
/*   Updated: 2022/11/04 10:21:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define SIZE 70
#define AND &&
#define OR ||
#define P != -1

void	printvect(t_vector v)
{
	printf("(%f, %f, %f, %f)\n", v.x, v.y, v.z, v.w);
}

t_vector	screen_position(t_camera cam, int x, int y)
{
	t_vector	res;

	res = m4mult(ft_vect(x, y, - cam.map.map[y][x] - 1), cam.rotz, 0);
	res = m4mult(res, cam.rotx, 0);
	res.z += (sqrt(cam.map.size.x * cam.map.size.x + cam.map.size.y * cam.map.size.y) + 10);
	if (cam.mode == 1)
	{
		res = m4mult(res, cam.m, 1);
		res.x *= 500;
		res.y *= 500;
	}
	else
	{
		res = m4mult(res, cam.m, 0);
		res.x *= 20;
		res.y *= 20;
	}
	res.x += cam.xoff;
	res.y += cam.yoff;
	return (res);
}

t_vector	ft_nulvect(void)
{
	return (ft_vec4(0, 0, 0, 0));
}

t_vector	ft_fvect(void)
{
	return (ft_vec4(-1, -1, -1, -1));
}

void	draw(t_camera cam, int x, int y)
{
	t_vector	pos1;
	t_vector	pos2;
	t_vector	pos3;

	pos2 = ft_fvect();
	pos3 = ft_fvect();
	pos1 = screen_position(cam, x, y);
	if (x + 1 < cam.map.size.x)
		pos2 = screen_position(cam, x + 1, y);
	if (y + 1 < cam.map.size.y)
		pos3 = screen_position(cam, x, y + 1);
	if (x + 1 < cam.map.size.x)
		ft_draw_gline(&cam.w.cvs, ft_line(pos1, pos2), cam.gradients[cam.cgrad], ft_vect(cam.map.map[y][x], cam.map.map[y][x + 1], cam.max));
	if (y + 1 < cam.map.size.y)
		ft_draw_gline(&cam.w.cvs, ft_line(pos1, pos3), cam.gradients[cam.cgrad], ft_vect(cam.map.map[y][x], cam.map.map[y + 1][x], cam.max));
}

void	joining(t_camera cam)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cam.map.size.x)
	{
		y = -1;
		while (++y < cam.map.size.y)
		{
			draw(cam, x, y);
		}
	}
}

int	hook_mgl(int key, t_camera *cam)
{
	handle_input(key, cam);
	rot(cam);
	ft_fill_canvas(cam->w.cvs, cam->backgrounds[cam->cback]);
	joining(*cam);
	ft_putimg(cam->w, cam->w.cvs.img, ft_vec2(0, 0));
	return (0);
}

int	main(int argc, char **argv)
{
	t_camera	cam;
	char		**text;

	if (argc != 2)
	{
		ft_putendl("fdf: usage: ./fdf <file.fdf>");
		return (0);
	}
	text = ft_read_lignes(argv[1]);
	if (text == 0)
		return (0);
	(void) malloc(123123);
	cam.map = ft_atoim(text, ' ');
	ft_putstra_join(text, "\n", 1);
	ft_free_pp((void **)text);
	if (cam.map.map == 0)
		ft_garbage_colector(0, 1, 1);
	ft_mlx_init(&cam.w, 800, 800, "fdf");
	cam.w.cvs = ft_init_canvas(cam.w.mlx, 800, 800);
	init_camera(&cam);
	hook_mgl(0, &cam);
	mlx_hook(cam.w.win, 2, 0, &hook_mgl, &cam);
	mlx_loop(cam.w.mlx);
}
