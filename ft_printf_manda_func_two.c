/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:34:02 by salee2            #+#    #+#             */
/*   Updated: 2022/08/05 16:37:01 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	u_func(va_list ap)
{
	ssize_t			ret;
	unsigned int	u;
	char			*str;

	u = va_arg(ap, unsigned int);
	str = ft_utoa(u);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

ssize_t	xl_func(va_list ap)
{
	ssize_t			ret;
	unsigned int	u;
	int				idx;
	char			hex[HEX_LEN];
	const char		*to_hex = "0123456789abcdef";

	u = va_arg(ap, unsigned int);
	ft_bzero(hex, HEX_LEN);
	idx = HEX_LEN - 1;
	if (u == 0)
		hex[--idx] = to_hex[0];
	while (idx > 0 && u)
	{
		hex[--idx] = to_hex[u % 16];
		u /= 16;
	}
	ret = write(1, hex + idx, ft_strlen(hex + idx));
	return (ret);
}

ssize_t	xu_func(va_list ap)
{
	ssize_t			ret;
	unsigned int	u;
	int				idx;
	char			hex[HEX_LEN];
	const char		*to_hex = "0123456789ABCDEF";

	u = va_arg(ap, unsigned int);
	ft_bzero(hex, HEX_LEN);
	idx = HEX_LEN - 1;
	if (u == 0)
		hex[--idx] = to_hex[0];
	while (idx > 0 && u)
	{
		hex[--idx] = to_hex[u % 16];
		u /= 16;
	}
	ret = write(1, hex + idx, ft_strlen(hex + idx));
	return (ret);
}

ssize_t	percent_func(va_list ap)
{
	ssize_t	ret;

	if (ap == NULL)
		return (-1);
	ret = write(1, "%", 1);
	return (ret);
}
