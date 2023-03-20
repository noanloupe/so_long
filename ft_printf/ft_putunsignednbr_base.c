/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:46:38 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 10:39:09 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsignednbr_base(unsigned int nbr, char *base, int *count)
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
		ft_putunsignednbr_base(nb / baselen, base, count);
		nb %= baselen;
	}
	if (nb < baselen)
	{
		write(1, &base[nb], 1);
		++(*count);
	}
}
