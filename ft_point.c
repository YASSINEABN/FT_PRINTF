/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:38:25 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/18 23:40:01 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_addrhexa(unsigned long nbr, char check, int *size)
{
	char	*str;

	if (check == 'x')
		str = "0123456789abcdef";
	else if (check == 'X')
		str = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(str[nbr], size);
	else
	{
		ft_addrhexa(nbr / 16, check, size);
		ft_addrhexa(nbr % 16, check, size);
	}
}

void	ft_point(unsigned long nbr, int *count)
{
	ft_putstr("0x", count);
	ft_addrhexa(nbr, 'x', count);
}
