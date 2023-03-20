/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:33 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 10:37:17 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb)
{
	int	count;

	count = 0;
	ft_putunsignednbr_base((int)nb, "0123456789", &count);
	return (count);
}

int	ft_print_x(int nb)
{
	int	count;

	count = 0;
	ft_putunsignednbr_base(nb, "0123456789abcdef", &count);
	return (count);
}

int	ft_print_caps_x(int nb)
{
	int	count;

	count = 0;
	ft_putunsignednbr_base(nb, "0123456789ABCDEF", &count);
	return (count);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_error(void)
{
	write(1, "[error: unknown conversion type character]", 42);
	return (42);
}
