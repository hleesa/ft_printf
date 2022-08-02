/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:23:10 by salee2            #+#    #+#             */
/*   Updated: 2022/07/25 17:24:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void set_func_num(int *to_func_num)
{
	size_t			i;
	const char		*conversions = "cspdiuxX%";
	const size_t	len = ft_strlen(conversions);

	i = 0;
//	ft_memset(to_func_num, -1, 256);
	while (i < 256)
		to_func_num[i++] = -1;
	i = 0;
	while (i < len)
	{
		to_func_num[conversions[i]] = i;
		++i;
	}
	return;
}

void set_num_to_func(char (*num_to_func[9])())
{
	num_to_func[0] = c_func;
	num_to_func[1] = s_func;
	num_to_func[2] = p_func;
	num_to_func[3] = d_func;
	num_to_func[4] = i_func;
	num_to_func[5] = u_func;
	num_to_func[6] = x_func;
	num_to_func[7] = X_func;
	num_to_func[8] = percnet_func;
	return;
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				to_func_num[256];
	char			(*num_to_func[9])();
	size_t			idx;
	size_t			pct_idx;
	char			ret_str;

	set_func_num(to_func_num);
	set_num_to_func(num_to_func);
	va_start(ap, format);
	idx = 0;
	ret_str = 0;
	while(idx < ft_strlen(format))
	{
		pct_idx = ft_strchr(format + idx, '%');
		if (pct_idx == 0)
		{
			ret_str = ft_strjoin(ret_str, format + idx);
			break;
		}
		ret_str = ft_strjoin(ret_str, pct_idx);
	}
	va_end(ap);
	printf("\n");
}

int main()
{
//	ft_printf("hello", "world", "hell", "hi");

	printf("%s\n", "01234" );
	return 0;
}