/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:17:15 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 10:37:56 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *count)
{
	long int	nb;
	int			baselen;

	if (!base)
		return ;
	nb = nbr;
	baselen = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		++(*count);
		nb *= -1;
	}
	while (base[baselen])
		++baselen;
	if (nb >= baselen)
	{
		ft_putnbr_base(nb / baselen, base, count);
		nb %= baselen;
	}
	if (nb < baselen)
	{
		write(1, &base[nb], 1);
		++(*count);
	}
}
