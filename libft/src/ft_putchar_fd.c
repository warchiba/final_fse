/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:08:24 by whorpe            #+#    #+#             */
/*   Updated: 2019/09/25 17:20:07 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char tmp;

	if (!fd)
		return ;
	tmp = (unsigned char)c;
	if (tmp <= 127)
		write(fd, &tmp, 1);
	else
	{
		tmp = 192 + ((unsigned char)c / 64);
		write(fd, &tmp, 1);
		tmp = 128 + ((unsigned char)c % 64);
		write(fd, &tmp, 1);
	}
}
