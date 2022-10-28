/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:04:31 by warchiba          #+#    #+#             */
/*   Updated: 2020/02/13 15:08:04 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modify_elements(float *tmp_coord, t_fdf *fdf, int *z1, int *z2)
{
	*z1 = fdf->matrix[(int)tmp_coord[1]][(int)tmp_coord[0]];
	*z2 = fdf->matrix[(int)tmp_coord[3]][(int)tmp_coord[2]];
	tmp_coord[0] *= fdf->zoom;
	tmp_coord[1] *= fdf->zoom;
	tmp_coord[2] *= fdf->zoom;
	tmp_coord[3] *= fdf->zoom;
	projection(tmp_coord, fdf, z1, z2);
	fdf->color = (*z1 > 0 || *z2 > 0) ? 0xf78fa7 : 0xffffff;
	fdf->color = (*z1 < 0 || *z2 < 0) ? 0x8ac8ff : fdf->color;
	tmp_coord[0] += fdf->x_offset;
	tmp_coord[2] += fdf->x_offset;
	tmp_coord[1] += fdf->y_offset;
	tmp_coord[3] += fdf->y_offset;
}

void	draw_line(float *tmp_coord, t_fdf *fdf)
{
	float	delta_x;
	float	delta_y;
	float	max;
	int		z1;
	int		z2;

	modify_elements(tmp_coord, fdf, &z1, &z2);
	delta_x = tmp_coord[2] - tmp_coord[0];
	delta_y = tmp_coord[3] - tmp_coord[1];
	max = ft_max(ft_abs(delta_x), ft_abs(delta_y));
	delta_x = delta_x / max;
	delta_y = delta_y / max;
	while (((int)(tmp_coord[0] - tmp_coord[2]) != 0) ||
	((int)(tmp_coord[1] - tmp_coord[3]) != 0))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
				tmp_coord[0], tmp_coord[1], fdf->color);
		tmp_coord[0] = tmp_coord[0] + delta_x;
		tmp_coord[1] = tmp_coord[1] + delta_y;
	}
	free(tmp_coord);
}

float	*coord_create(float x1, float y1, float x2, float y2)
{
	float *coord;

	coord = (float*)malloc(sizeof(float) * 4);
	coord[0] = x1;
	coord[1] = y1;
	coord[2] = x2;
	coord[3] = y2;
	return (coord);
}

void	draw(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				draw_line(coord_create(x, y, x + 1, y), fdf);
			if (y != fdf->height - 1)
				draw_line(coord_create(x, y, x, y + 1), fdf);
			x++;
		}
		y++;
	}
}
