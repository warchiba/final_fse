/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:20:59 by whorpe            #+#    #+#             */
/*   Updated: 2019/10/30 11:21:11 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Create a new block structure.
*/

t_block		*block_new(int x, int y)
{
	t_block		*block;

	block = ft_memalloc(sizeof(t_block));
	block->x = x;
	block->y = y;
	return (block);
}
