/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:03 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/18 23:45:01 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(char c, va_list args, int *count)
{
	unsigned long	p;

	if (c == 's')
		ft_putstr(va_arg(args, char *), count);
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
		if (!p)
			ft_putstr("(nil)", count);
		else
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
// int	main(void)
// {
// 	// char	*str;
// 	// int		d;
// 	// int		a;
// 	// int		b;
// 	// char	*p;

// 	// str = "yassine";
// 	// d = -2147483648;
// 	// p = 0;
// 	// int x = ft_printf("%");
// 	// char *a = NULL;

// 	// a = printf(" a :   hello %s %c %d %p %u % \n", str, 'h', d, p, -5);
// 	// b = ft_printf(" b :   hello %s %c %d %p %u  \n", str, 'h', d, p, -5);
// 	// printf("%/ \n");
// 	// printf("%i");
// 	// printf("a :%d ||   b:%d     ",a,b);

// 	// printf("%");
// 	int a = ft_printf("%%%");
// 	printf("%d",a);
// 	//   ft_printf("%d",ft_printf("%"));

// 	return (0);
// }
