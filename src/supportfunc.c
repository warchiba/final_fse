/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:49:03 by warchiba          #+#    #+#             */
/*   Updated: 2019/11/01 16:33:53 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		find_xymax(t_tetrimin *tet, int *xmax, int *ymax)
{
	int i;

	i = 0;
	*xmax = 0;
	*ymax = 0;
	while (i < 8)
	{
		if (tet->id[i] > *xmax)
			*xmax = tet->id[i];
		if (tet->id[i + 1] > *ymax)
			*ymax = tet->id[i + 1];
		i = i + 2;
	}
}

char		**split_tab(char *str)
{
	char	**tab;
	int		i;
	int		k;

	tab = (char**)malloc(sizeof(char*) * 4);
	i = 0;
	k = 0;
	while (i < 20)
	{
		if ((i == 0) || (str[i - 1] == '\0'))
		{
			tab[k] = &str[i];
			k++;
		}
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (tab);
}

void		ft_lstrev(t_tetrimin **list)
{
	t_tetrimin	*tet;
	t_tetrimin	*tmp;
	t_tetrimin	*tmp1;

	tet = *list;
	tmp = NULL;
	while (tet)
	{
		tmp1 = tet->next;
		tet->next = tmp;
		tmp = tet;
		tet = tmp1;
	}
	*list = tmp;
}

void		print_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

t_tetrimin	*free_list(t_tetrimin **list)
{
	t_tetrimin *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->id);
		free(*list);
		(*list) = tmp;
	}
	*list = NULL;
	return (NULL);
}
