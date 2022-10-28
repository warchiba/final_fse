/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:16:21 by warchiba          #+#    #+#             */
/*   Updated: 2020/02/22 22:16:26 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(float *x, float *y, int z)
{
	*x = *x + z * cos(0.8);
	*y = *y + z * sin(0.8);
}

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	float	u;
	float	v;

	u = *x;
	v = *y;
	*x = u * cos(fdf->angle_y) + z * sin(fdf->angle_y);
	*y = u * sin(fdf->angle_x) * sin(fdf->angle_y) + v * cos(fdf->angle_x)
	- z * sin(fdf->angle_x) * cos(fdf->angle_y);
}

void	projection(float *tmp_coord, t_fdf *fdf, int *z1, int *z2)
{
	if (fdf->projection == 1)
	{
		isometric(&tmp_coord[0], &tmp_coord[1], *z1, fdf);
		isometric(&tmp_coord[2], &tmp_coord[3], *z2, fdf);
	}
	else
	{
		parallel(&tmp_coord[0], &tmp_coord[1], *z1);
		parallel(&tmp_coord[2], &tmp_coord[3], *z2);
	}
}
