/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:34:02 by salee2            #+#    #+#             */
/*   Updated: 2022/08/06 11:07:07 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char			*ret;
	const size_t	size = get_size(n);

	ret = (char *) malloc(size + 1);
	if (ret == 0)
		return (0);
	to_string(n, ret, size - 1, size);
	ret[size] = '\0';
	return (ret);
}