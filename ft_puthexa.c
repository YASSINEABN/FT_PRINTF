/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:29 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/18 13:46:30 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nbr, char check, int *size)
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
		ft_puthexa(nbr / 16, check, size);
		ft_puthexa(nbr % 16, check, size);
	}
}
