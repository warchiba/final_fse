/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:52:06 by warchiba          #+#    #+#             */
/*   Updated: 2019/10/31 13:06:55 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check(char **tab, t_tetrimin *tet)
{
	if (tab[tet->x_offset + tet->id[0]][tet->y_offset + tet->id[1]] != '.')
		return (0);
	if (tab[tet->x_offset + tet->id[2]][tet->y_offset + tet->id[3]] != '.')
		return (0);
	if (tab[tet->x_offset + tet->id[4]][tet->y_offset + tet->id[5]] != '.')
		return (0);
	if (tab[tet->x_offset + tet->id[6]][tet->y_offset + tet->id[7]] != '.')
		return (0);
	return (1);
}

void	tet_print(char **tab, t_tetrimin *tet)
{
	tab[tet->x_offset + tet->id[0]][tet->y_offset + tet->id[1]] = tet->letter;
	tab[tet->x_offset + tet->id[2]][tet->y_offset + tet->id[3]] = tet->letter;
	tab[tet->x_offset + tet->id[4]][tet->y_offset + tet->id[5]] = tet->letter;
	tab[tet->x_offset + tet->id[6]][tet->y_offset + tet->id[7]] = tet->letter;
}

void	tet_delete(char **tab, t_tetrimin *tet)
{
	tab[tet->x_offset + tet->id[0]][tet->y_offset + tet->id[1]] = '.';
	tab[tet->x_offset + tet->id[2]][tet->y_offset + tet->id[3]] = '.';
	tab[tet->x_offset + tet->id[4]][tet->y_offset + tet->id[5]] = '.';
	tab[tet->x_offset + tet->id[6]][tet->y_offset + tet->id[7]] = '.';
}

int		change_offset(t_tetrimin *tet, int size)
{
	int		xmax;
	int		ymax;

	find_xymax(tet, &xmax, &ymax);
	while (1)
	{
		tet->x_offset = tet->x_offset + (tet->y_offset + 1) / size;
		tet->y_offset = (tet->y_offset + 1) % size;
		if ((tet->x_offset + xmax) == size)
		{
			tet->x_offset = 0;
			tet->y_offset = 0;
			return (0);
		}
		if ((tet->y_offset + ymax) < size)
			return (1);
	}
}

int		solve(char **tab, t_tetrimin *tet, int size)
{
	if (!tet)
		return (1);
	while (1)
	{
		while (!check(tab, tet))
			if (!change_offset(tet, size))
				return (0);
		tet_print(tab, tet);
		if (solve(tab, tet->next, size))
			return (1);
		tet_delete(tab, tet);
		if (!change_offset(tet, size))
			return (0);
	}
}
