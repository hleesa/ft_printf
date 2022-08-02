/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:01:24 by salee2            #+#    #+#             */
/*   Updated: 2022/07/29 20:01:26 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

char*	c_func(va_list ap);
char*	s_func(va_list ap);
char*	p_func(va_list ap);
char*	d_func(va_list ap);
char*	i_func(va_list ap);
char*	u_func(va_list ap);
char*	x_func(va_list ap);
char*	X_func(va_list ap);
char*	percnet_func(va_list ap);

#endif //FT_PRINTF_H
