/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:01:24 by salee2            #+#    #+#             */
/*   Updated: 2022/08/03 11:58:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define HEX_ADDR_LEN 19
# define HEX_LEN 9

char	*c_func(va_list ap);
char	*s_func(va_list ap);
char	*p_func(va_list ap);
char	*d_func(va_list ap);
char	*i_func(va_list ap);
char	*u_func(va_list ap);
char	*xl_func(va_list ap);
char	*xu_func(va_list ap);
char	*percnet_func(void);

#endif //FT_PRINTF_H
