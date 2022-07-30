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
	char c = va_arg(ap, const char *);
	return (ft_itoa(c));
}

char*	s_func(va_list ap)
{
	return (ft_strdup(va_arg(ap, const char *)));
}

char*	p_func(va_list ap)
{

}

char*	d_func(va_list ap)
{

}

char*	i_func(va_list ap)
{

}
char*	u_func(va_list ap)
{

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