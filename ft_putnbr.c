/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:45:56 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/18 13:47:18 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", count);
	else if (nb < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}
