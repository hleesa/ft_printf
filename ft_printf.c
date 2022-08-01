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
	while (i < 256)
	{
		to_func_num[i] = -1;
		++i;
	}
	i = 0;
	while (i < len)
	{
		to_func_num[conversions[i]] = i;
		++i;
	}
	return;
}

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
	const char			*to_hex= "0123456789abcdef";
	char				hex_addr[18];
	int					idx;

	addr = va_arg(ap, unsigned long long);
	idx = 0;
	while(idx < 18)
		hex_addr[idx++] = 0;
	idx = 17;
	while(addr)
	{
		hex_addr[idx] = to_hex[addr%16];
		addr /= 16;
		--idx;
	}
	hex_addr[idx] = 'x';
	hex_addr[idx - 1] = '0';
	return (ft_strdup(hex_addr + idx - 1));
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

char*	u_func(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	return (ft_utoa(u));
}
char*	x_func(va_list ap)
{

}
char*	X_func(va_list ap)
{

}
char*	percnet_func(va_list ap)
{
	return (ft_strdup("%"));
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
int	ft_printf(const char * format, ...)
{
	int to_func_num[256];
	char (*num_to_func[9])();

	set_func_num(to_func_num);
	set_num_to_func(num_to_func);

	for(int i=0; i<256; ++i)
	{
		printf("%d %d\n", i, to_func_num[i]);
	}
	va_list ap;
	va_start(ap, format);
	c_func(ap);
	printf("%c", 100);
	printf("%s\n", format);
	printf("%d\n", va_arg(ap, const char *));
	printf("%s\n", va_arg(ap, const char *));
	printf("%s\n", va_arg(ap, const char *));

	va_end(ap);
	printf("\n");
}

int main()
{
//	ft_printf("hello", "world", "hell", "hi");

	printf("%s\n", "01234" );
	return 0;
}