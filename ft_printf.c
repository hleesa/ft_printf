/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:23:10 by salee2            #+#    #+#             */
/*   Updated: 2022/08/03 15:06:47 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	set_func_num(int *to_func_num)
{
	size_t			i;
	const  char		*conversions = "cspdiuxX%";
	unsigned char	*cp = conversions;

	const size_t	len = ft_strlen(conversions);

	ft_memset(to_func_num, -1, 256);
	i = 0;
	while (i < len)
	{
		to_func_num[cp[i]] = i;
		++i;
	}
	return ;
}

void	set_num_to_func(char *(*num_to_func[9])())
{
	num_to_func[0] = c_func;
	num_to_func[1] = s_func;
	num_to_func[2] = p_func;
	num_to_func[3] = d_func;
	num_to_func[4] = i_func;
	num_to_func[5] = u_func;
	num_to_func[6] = xl_func;
	num_to_func[7] = xu_func;
	num_to_func[8] = percnet_func;
	return ;
}

int	is_error(const char *format, int *to_func_num)
{
	size_t			idx;
	const size_t	len = ft_strlen(format);

	if (format == NULL)
		return (1);
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if (idx + 1 == len || to_func_num[format[idx]] == -1)
				return (1);
		}
		++idx;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				to_func_num[256];
	char			*(*num_to_func[9])(va_list);
	size_t			idx;
	const size_t	format_len = ft_strlen(format);

	set_func_num(to_func_num);
	set_num_to_func(num_to_func);
	if (is_error(format, to_func_num))
		return (-1);
	va_start(ap, format);
	idx = 0;
	while (idx < format_len)
	{
		if (format[idx] == '%')
		{
			ft_putstr_fd(num_to_func[to_func_num[format[idx + 1]]](ap), 1);
			++idx;
		}
		else
			ft_putchar_fd(format[idx], 1);
		++idx;
	}
	va_end(ap);
	return (0);
}

int main()
{
	ft_printf("hello %d\n", 100);
	printf("hello %d\n", 100);

	return 0;
}
