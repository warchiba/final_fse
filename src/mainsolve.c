/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsolve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:16:25 by warchiba          #+#    #+#             */
/*   Updated: 2019/11/03 18:16:35 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		find_size(t_tetrimin *tet)
{
	int		cmax;
	int		k;
	int		i;

	cmax = 0;
	k = 0;
	while (tet)
	{
		k++;
		i = 0;
		while (i < 8)
		{
			if (tet->id[i] > cmax)
				cmax = tet->id[i];
			i++;
		}
		tet = tet->next;
	}
	i = 0;
	while (i * i < k * 4)
		i++;
	return (max(i, cmax + 1));
}

char	**create_tab(int size)
{
	int		i;
	int		j;
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = (char*)malloc(size);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

void	free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**main_solve(t_tetrimin *tet, int *size)
{
	char	**tab;

	*size = find_size(tet);
	tab = create_tab(*size);
	while (!solve(tab, tet, *size))
	{
		free_tab(tab, *size);
		(*size)++;
		tab = create_tab(*size);
	}
	return (tab);
}
