/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:24:41 by salee2            #+#    #+#             */
/*   Updated: 2022/08/01 13:24:52 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

long long	toll(const char *str, long long sign, size_t i)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0;
	while (ft_isdigit(str[i]))
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[i] - '0' \
					> (llmax % 10)))
		{
			if (sign == 1)
				return (LONG_LONG_MAX);
			else
				return (LONG_LONG_MIN);
		}
		acc = acc * 10 + str[i] - '0';
		++i;
	}
	return (sign * acc);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	sign;

	i = 0;
	sign = 1;
	while (isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	return ((int) toll(str, sign, i));
}
