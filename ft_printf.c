/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:23:10 by salee2            #+#    #+#             */
/*   Updated: 2022/08/05 18:03:21 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_func_num(int *to_func_num)
{
	size_t			i;
	const char		*conversions = "cspdiuxX%";
	const size_t	len = ft_strlen(conversions);

	ft_memset(to_func_num, -1, 256);
	i = 0;
	while (i < len)
	{
		to_func_num[((const unsigned char *)conversions)[i]] = i;
		++i;
	}
	return ;
}

void	set_num_to_func(ssize_t	(*num_to_func[9])())
{
	num_to_func[0] = c_func;
	num_to_func[1] = s_func;
	num_to_func[2] = p_func;
	num_to_func[3] = d_func;
	num_to_func[4] = i_func;
	num_to_func[5] = u_func;
	num_to_func[6] = xl_func;
	num_to_func[7] = xu_func;
	num_to_func[8] = percent_func;
	return ;
}

int	is_error(const char *format, int *to_func_num)
{
	size_t			i;
	const size_t	len = ft_strlen(format);

	if (format == NULL)
		return (1);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (++i == len || \
					to_func_num[((const unsigned char *)format)[i]] == -1)
				return (1);
		}
		++i;
	}
	return (0);
}

int	print_format(const char *format, va_list ap, \
		int *to_func_num, ssize_t (*num_to_func[9])(va_list))
{
	size_t			i;
	ssize_t			print_byte;
	ssize_t			print_total_byte;
	const size_t	format_len = ft_strlen(format);
	int				num_of_func;

	i = 0;
	print_byte = 0;
	print_total_byte = 0;
	while (i < format_len)
	{
		if (format[i] == '%')
		{
			num_of_func = to_func_num[((const unsigned char *)format)[i + 1]];
			print_byte = num_to_func[num_of_func](ap);
			++i;
		}
		else
			print_byte = write(1, format + i, 1);
		if (print_byte == -1)
			return (-1);
		print_total_byte += print_byte;
		++i;
	}
	return (print_total_byte);
}

int	ft_printf(const char *format, ...)
{
	ssize_t		ret;
	va_list		ap;
	int			to_func_num[256];
	ssize_t		(*num_to_func[9])(va_list);

	set_func_num(to_func_num);
	set_num_to_func(num_to_func);
	if (is_error(format, to_func_num))
		return (-1);
	va_start(ap, format);
	ret = print_format(format, ap, to_func_num, num_to_func);
	va_end(ap);
	return (ret);
}
