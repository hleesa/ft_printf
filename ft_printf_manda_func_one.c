/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_manda_func_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:12 by salee2            #+#    #+#             */
/*   Updated: 2022/08/02 11:02:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*	c_func(va_list ap)
{
	const char c = va_arg(ap, char);	// char ok?
	return (ft_itoa(c));
}

char*	s_func(va_list ap)
{
	return (ft_strdup(va_arg(ap, const char *)));
}

char*	p_func(va_list ap)
{
	unsigned long long	addr;
	int					idx;
	const int 			hex_addr_len = 16 + 2 + 1;
	char				hex_addr[hex_addr_len];
	const char			*to_hex= "0123456789abcdef";

	addr = va_arg(ap, unsigned long long);
	ft_bzero(hex_addr, hex_addr_len);
	idx = hex_addr_len - 1;
	while(addr)
	{
		--idx;
		hex_addr[idx] = to_hex[addr%16];
		addr /= 16;
	}
	hex_addr[--idx] = 'x';
	hex_addr[--idx] = '0';
	return (ft_strdup(hex_addr + idx));
}

char*	d_func(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	return (ft_itoa(d));
}

char*	i_func(va_list ap)
{
	return (d_func(ap));
}