/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:22 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/18 23:51:09 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *ptr);
void	ft_putstr(char *txt, int *ptr);
void	ft_putnbr(int nb, int *count);
void	ft_puthexa(unsigned	int nbr, char check, int *size);
void	ft_point(unsigned long nbr, int *count);
int		ft_printf(const char *count, ...);
void	ft_putunsigned(unsigned long nb, int *count);
char	*ft_strchr(const char *s, int c);
#endif