/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:27:59 by whorpe            #+#    #+#             */
/*   Updated: 2019/11/03 20:38:20 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** We need 6 or 8 connections to be valid.
*/

int			checking_connections(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
** Verifying for '#' and '.' and blocks.
*/

int			verify_chars(char *str, int count)
{
	int		i;
	int		blocks;

	blocks = 0;
	i = 0;
	if (count < 20)
		return (6);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (!checking_connections(str))
		return (5);
	return (0);
}

t_tetrimin	*reading_tetris(int fd)
{
	char		buf[BUFF_SIZE];
	int			count;
	int			f;
	t_tetrimin	*list[2];
	char		cur;

	list[0] = NULL;
	cur = 'A' - 1;
	f = 1;
	while ((count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((verify_chars(buf, count) != 0) || (cur++ > 'Z') || !f)
			return (free_list(&list[0]));
		else
		{
			list[1] = create_list(buf, cur);
			list[1]->next = list[0];
			list[0] = list[1];
		}
		f = ((count == 20) || (buf[20] != '\n')) ? 0 : 1;
	}
	if (f)
		return (free_list(&list[0]));
	ft_lstrev(&list[0]);
	return (list[0]);
}
