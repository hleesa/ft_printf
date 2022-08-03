/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:22 by salee2            #+#    #+#             */
/*   Updated: 2022/08/03 11:57:26 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_func(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	return (ft_utoa(u));
}

char	*xl_func(va_list ap)
{
	unsigned int	u;
	int				idx;
	char			hex[HEX_LEN];
	const char		*to_hex = "0123456789abcdef";

	u = va_arg(ap, unsigned int);
	ft_bzero(hex, HEX_LEN);
	idx = HEX_LEN - 1;
	while (u)
	{
		--idx;
		hex[idx] = to_hex[u % 16];
		u /= 16;
	}
	return (ft_strdup(hex + idx));
}

char	*xu_func(va_list ap)
{
	unsigned int	u;
	int				idx;
	char			hex[HEX_LEN];
	const char		*to_hex = "0123456789ABCDEF";

	u = va_arg(ap, unsigned int);
	ft_bzero(hex, HEX_LEN);
	idx = HEX_LEN - 1;
	while (u)
	{
		--idx;
		hex[idx] = to_hex[u % 16];
		u /= 16;
	}
	return (ft_strdup(hex + idx));
}

char	*percnet_func(va_list ap)
{
	return (ft_strdup("%"));
}
