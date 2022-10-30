/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:18:43 by whorpe            #+#    #+#             */
/*   Updated: 2019/09/25 17:17:46 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(++size))
		return (0);
	str = ft_memalloc(size);
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, '\0', size);
	return (str);
}
