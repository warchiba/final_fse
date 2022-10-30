/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:03:58 by whorpe            #+#    #+#             */
/*   Updated: 2019/11/03 18:57:14 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Stating main structure and launching functions.
*/

int		main(int ac, char **av)
{
	t_tetrimin	*list;
	int			size;
	char		**tab;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	if ((list = reading_tetris(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putendl("error");
		return (1);
	}
	tab = main_solve(list, &size);
	print_tab(tab, size);
	free_tab(tab, size);
	free_list(&list);
	return (0);
}
