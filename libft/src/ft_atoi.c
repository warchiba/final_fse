/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:30:00 by whorpe            #+#    #+#             */
/*   Updated: 2019/09/25 17:29:12 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			sign;
	long long	num;
	long long	check;

	num = 0;
	check = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = num;
		num = (num * 10) + *str++ - '0';
		if (num < check)
			return ((sign == 1) ? (-1) : (0));
	}
	return (num * sign);
}
