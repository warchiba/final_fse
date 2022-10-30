/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:00:22 by whorpe            #+#    #+#             */
/*   Updated: 2019/09/07 21:00:24 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr = (unsigned char*)content;
	ptr2 = (unsigned char*)new;
	while (*ptr)
		*(ptr2++) = *(ptr++);
	return (new);
}
