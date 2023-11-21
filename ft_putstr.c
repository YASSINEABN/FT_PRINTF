/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:34 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/21 10:35:14 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *txt, int *ptr)
{
	int	i;

	i = 0;
	if (txt == NULL)
	{
		ft_putstr("(null)", ptr);
	}
	else
	{
		while (txt[i])
		{
			ft_putchar(txt[i], ptr);
			i++;
		}
	}
}
