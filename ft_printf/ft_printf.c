/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:17 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 16:26:14 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char c, va_list var)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(va_arg(var, int));
	else if (c == 's')
		count = ft_print_s(va_arg(var, char *));
	else if (c == 'p')
		count = ft_print_p(va_arg(var, void *));
	else if (c == 'd')
		count = ft_print_d(va_arg(var, int));
	else if (c == 'i')
		count = ft_print_i(va_arg(var, int));
	else if (c == 'u')
		count = ft_print_u(va_arg(var, unsigned int));
	else if (c == 'x')
		count = ft_print_x(va_arg(var, int));
	else if (c == 'X')
		count = ft_print_caps_x(va_arg(var, int));
	else if (c == '%')
		count = ft_print_percent();
	else
		count = ft_print_error();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		count;

	va_start(var, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_conversion(*str, var);
		}
		else
		{
			write(1, str, 1);
			++count;
		}
		str++;
	}
	va_end(var);
	return (count);
}
