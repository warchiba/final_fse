/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:26:50 by warchiba          #+#    #+#             */
/*   Updated: 2020/01/15 16:26:53 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_fdf(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->matrix[i])
	{
		free(fdf->matrix[i]);
		i++;
	}
	free(fdf->matrix);
	free(fdf);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "My FdF");
	fdf->zoom = 20;
	fdf->x_offset = 150;
	fdf->y_offset = 150;
	fdf->angle_x = asin(sqrt(3) / 3);
	fdf->angle_y = 3.14 / 4;
	fdf->projection = 1;
}

void	deal_key_part2(int key, t_fdf *fdf)
{
	if (key == 24)
		fdf->zoom += 1;
	if (key == 27)
		fdf->zoom -= 1;
	if (key == 13)
		fdf->angle_x += 0.05;
	if (key == 1)
		fdf->angle_x -= 0.05;
	if (key == 2)
		fdf->angle_y += 0.05;
	if (key == 0)
		fdf->angle_y -= 0.05;
	if (key == 35)
		fdf->projection = 2;
	if (key == 34)
	{
		fdf->angle_x = 3.14 / 2 - asin(sqrt(3) / 3);
		fdf->angle_y = 3.14 / 4;
		fdf->projection = 1;
	}
}

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->y_offset -= 10;
	if (key == 124)
		fdf->x_offset += 10;
	if (key == 125)
		fdf->y_offset += 10;
	if (key == 123)
		fdf->x_offset -= 10;
	if (key == 53)
	{
		clear_fdf(fdf);
		exit(0);
	}
	deal_key_part2(key, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		write(1, "usage: ./fdf map_name\n", 22);
		exit(1);
	}
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	if (!fdf)
	{
		write(1, "Memory error! Sorry! Try again!\n", 32);
		exit(1);
	}
	ft_putstr("Key manual:\n\tarrows - moving fdf\n\t+ - increase\n");
	ft_putstr("\t- - decrease\n\tp - parallel projection");
	ft_putstr("\ti - isometric projection\n");
	ft_putstr("\tw,s,a,d - change angle (for iso)\n\tESC - exit\n");
	fdf_init(fdf);
	readfile(argv[1], fdf);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
