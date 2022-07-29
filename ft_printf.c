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

//int	ft_printf(const char *, ...)
//{
//
//}


#include <stdio.h>
void printNumber(int args, ...)
{
	va_list ap;

	va_start(ap, args);
	for (int i = 0; i < args; ++i)
	{
		int num = va_arg(ap, int);
		printf("%d ", num);
	}
	va_end(ap);

	printf("\n");
}
int main()
{
	printNumber(1, 10);
	printNumber(2, 10, 20);
	printNumber(3, 10, 20, 30);
	printNumber(4, 10, 20, 30, 40);

	return 0;
}