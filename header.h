/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 23:29:38 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "koflibc/sources.h"

typedef struct s_camera
{
	t_window	w;
	t_matrix	map;

	int			width;
	int			height;
	double		near;
	double		far;
	double		fov;
	double		ration;
	double		fovrad;
	double		m[4][4];
	double		theta;
	double		beta;
	double		rotx[4][4];
	double		rotz[4][4];
	double		yoff;
	double		xoff;
	int			mode;
	int			max;
	int			min;
	int			gradients[10][25];
	int			backgrounds[10];
	int			cgrad;
	int			cback;
}	t_camera;

t_vector	ft_normal(t_vector a, t_vector b, t_vector c);
t_vector	m4mult(t_vector pos, double m[4][4], int div);

void		rot(t_camera *cam);
void		init_camera(t_camera *cam);
double		dotprod(t_vector a, t_vector b);
void		rgb(int *pointer);
void		handle_input(int key, t_camera *cam);


void		gradient0(int *pointer);
void		gradient1(int *pointer);
void		gradient2(int *pointer);
void		gradient3(int *pointer);
void		gradient4(int *pointer);
void		gradient5(int *pointer);
void		gradient6(int *pointer);
void		gradient7(int *pointer);
void		gradient8(int *pointer);
void		gradient9(int *pointer);
#endif
