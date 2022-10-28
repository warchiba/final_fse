/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:27:09 by warchiba          #+#    #+#             */
/*   Updated: 2020/01/15 16:27:12 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_num(char *line)
{
	size_t	i;
	int		count;

	i = 1;
	if (line[0] != ' ')
		count = 1;
	else
		count = 0;
	while (i < ft_strlen(line))
	{
		if ((line[i] != ' ') && (line[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

int		is_valid(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if ((line[i] != '-') && (line[i] != ' ')
		&& ((line[i] < '0') || (line[i] > '9')))
			return (0);
		i++;
	}
	return (1);
}

void	get_height_width(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	int		w_check;

	fdf->height = 0;
	fdf->width = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		fdf->height++;
		w_check = count_num(line);
		if (((fdf->width != 0) && (w_check != fdf->width)) || !is_valid(line))
		{
			write(1, "Invalid map!\n", 13);
			exit(1);
		}
		fdf->width = w_check;
		free(line);
	}
	close(fd);
	free(line);
}

void	get_matrix(char *filename, int ***m)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**matrix;

	fd = open(filename, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		matrix = ft_strsplit(line, ' ');
		i = 0;
		while (matrix[i])
		{
			(*m)[j][i] = ft_atoi(matrix[i]);
			free(matrix[i]);
			i++;
		}
		j++;
		free(line);
		free(matrix);
	}
	free(line);
	close(fd);
}

void	readfile(char *filename, t_fdf *fdf)
{
	int		i;

	get_height_width(fdf, filename);
	fdf->matrix = (int**)malloc(sizeof(int*) * (fdf->height + 1));
	if (!fdf->matrix)
	{
		write(1, "Memory error! Sorry! Try again!\n", 32);
		exit(1);
	}
	i = -1;
	while (++i < fdf->height)
	{
		fdf->matrix[i] = (int*)malloc(sizeof(int) * fdf->width);
		if (!fdf->matrix[i])
		{
			write(1, "Memory error! Sorry! Try again!\n", 32);
			clear_fdf(fdf);
			exit(1);
		}
	}
	fdf->matrix[i] = NULL;
	get_matrix(filename, &(fdf->matrix));
}
