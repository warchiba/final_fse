/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:19:05 by warchiba          #+#    #+#             */
/*   Updated: 2019/11/03 18:19:08 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*modify_coord(int *coord)
{
	int i;
	int xmin;
	int ymin;

	i = 0;
	xmin = 3;
	ymin = 3;
	while (i < 8)
	{
		if (coord[i] < xmin)
			xmin = coord[i];
		if (coord[i + 1] < ymin)
			ymin = coord[i + 1];
		i = i + 2;
	}
	i = 0;
	while (i < 8)
	{
		coord[i] = coord[i] - xmin;
		coord[i + 1] = coord[i + 1] - ymin;
		i = i + 2;
	}
	return (coord);
}

int			*detect_id(char **tab)
{
	int		i;
	int		j;
	int		k;
	int		*coord;

	i = 0;
	k = 0;
	coord = (int*)malloc(sizeof(int) * 8);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				coord[k] = i;
				coord[k + 1] = j;
				k = k + 2;
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (modify_coord(coord));
}

t_tetrimin	*create_list(char *str, char letter)
{
	t_tetrimin	*tet;

	tet = (t_tetrimin *)malloc(sizeof(t_tetrimin));
	tet->letter = letter;
	tet->id = detect_id(split_tab(str));
	tet->x_offset = 0;
	tet->y_offset = 0;
	tet->next = NULL;
	return (tet);
}
