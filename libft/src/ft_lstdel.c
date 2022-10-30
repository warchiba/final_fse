/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:05:48 by whorpe            #+#    #+#             */
/*   Updated: 2019/09/07 21:05:50 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *alst;
	while (ptr)
	{
		tmp = ptr;
		ft_lstdelone(&ptr, del);
		ptr = tmp->next;
	}
	*alst = NULL;
}
