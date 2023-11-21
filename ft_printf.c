/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:03 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/21 10:38:43 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(char c, va_list args, int *count)
{
	unsigned long	p;
	char			*s;

	if (c == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s, count);
	}
	else if (c == 'c')
		ft_putchar((char)va_arg(args, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putunsigned(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(args, unsigned int), c, count);
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long);
		ft_point(p, count);
	}
	else if (c == '%')
		ft_putchar('%', count);
	else
		*count = -1;
}

int	ft_printf(const char *count, ...)
{
	va_list	args;
	int		i;
	int		length;

	length = 0;
	if (!count)
		return (-1);
	va_start(args, count);
	i = 0;
	length = 0;
	while (count[i])
	{
		if (count[i] == '%' && ft_strchr("cspdiuxX%", count[i + 1]))
		{
			check_flags(count[i + 1], args, &length);
			i++;
			if (length == -1)
				return (-1);
		}
		else
			ft_putchar(count[i], &length);
		i++;
	}
	va_end(args);
	return (length);
}
