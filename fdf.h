/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:27:00 by warchiba          #+#    #+#             */
/*   Updated: 2020/01/15 16:27:03 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# define BUFF_SIZE 1000000

typedef	struct
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		x_offset;
	int		y_offset;
	float	angle_x;
	float	angle_y;
	int		projection;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

int			get_next_line(const int fd, char **line);
float		ft_max(float a, float b);
float		ft_abs(float x);
void		ft_putstr(char const *s);
void		projection(float *tmp_coord, t_fdf *fdf, int *z1, int *z2);
void		readfile(char *filename, t_fdf *fdf);
void		draw(t_fdf *fdf);
void		clear_fdf(t_fdf *fdf);
#endif
