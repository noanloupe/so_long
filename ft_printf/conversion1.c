/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:23:43 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 11:02:45 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	count;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}

int	ft_print_p(void *ptr)
{
	unsigned long int	ad;
	int					count;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	count = 0;
	ad = (unsigned long int)ptr;
	write(1, "0x", 2);
	ft_putptr(ad, "0123456789abcdef", &count);
	return (count + 2);
}

int	ft_print_d(int nb)
{
	int	count;

	count = 0;
	ft_putnbr_base(nb, "0123456789", &count);
	return (count);
}

int	ft_print_i(int nb)
{
	int	count;

	count = 0;
	ft_putnbr_base(nb, "0123456789", &count);
	return (count);
}
