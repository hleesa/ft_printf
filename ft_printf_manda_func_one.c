/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:12 by salee2            #+#    #+#             */
/*   Updated: 2022/08/05 16:37:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	c_func(va_list ap)
{
	ssize_t	ret;
	char	c;

	c = va_arg(ap, int);
	ret = write(1, &c, 1);
	return (ret);
}

ssize_t	s_func(va_list ap)
{
	ssize_t		ret;
	const char	*str = va_arg(ap, const char *);

	if (str == NULL)
		ret = write(1, "(null)", 6);
	else
		ret = write(1, str, ft_strlen(str));
	return (ret);
}

ssize_t	p_func(va_list ap)
{
	ssize_t				ret;
	unsigned long long	addr;
	int					idx;
	char				hex_addr[HEX_ADDR_LEN];
	const char			*to_hex = "0123456789abcdef";

	addr = va_arg(ap, unsigned long long);
	ft_bzero(hex_addr, HEX_ADDR_LEN);
	idx = HEX_ADDR_LEN - 1;
	if (addr == 0)
		hex_addr[--idx] = to_hex[0];
	while (idx > 0 && addr)
	{
		hex_addr[--idx] = to_hex[addr % 16];
		addr /= 16;
	}
	hex_addr[--idx] = 'x';
	hex_addr[--idx] = '0';
	ret = write(1, hex_addr + idx, ft_strlen(hex_addr + idx));
	return (ret);
}

ssize_t	d_func(va_list ap)
{
	ssize_t	ret;
	int		d;
	char	*str;

	d = va_arg(ap, int);
	str = ft_itoa(d);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

ssize_t	i_func(va_list ap)
{
	return (d_func(ap));
}
