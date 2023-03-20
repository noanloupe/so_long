/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:12:46 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/27 10:38:29 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long int nbr, char *base, int *count)
{
	unsigned long int	baselen;

	baselen = ft_strlen(base);
	if (nbr >= baselen)
	{
		ft_putptr(nbr / baselen, base, count);
		nbr %= baselen;
	}
	if (nbr < baselen)
	{
		write(1, &base[nbr], 1);
		++(*count);
	}
}
