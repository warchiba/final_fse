/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helptools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:44:53 by warchiba          #+#    #+#             */
/*   Updated: 2020/02/22 22:44:55 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_abs(float x)
{
	if (x >= 0)
		return (x);
	return (-x);
}
