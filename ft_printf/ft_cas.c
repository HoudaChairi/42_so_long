/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:11:23 by hchairi           #+#    #+#             */
/*   Updated: 2023/02/28 13:36:00 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cas(va_list lst, const char *s, int i)
{
	int	count;

	count = 0;
	if (s[i] == '%')
		return (ft_putchar('%'));
	else if (s[i] == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (s[i] == 'p')
	{
		ft_putstr("0x");
		return (ft_hexanbr(va_arg(lst, unsigned long), "0123456789abcdef") + 2);
	}
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr(va_arg(lst, int)));
	else if (s[i] == 'u')
		return (ft_putnbr(va_arg(lst, unsigned int)));
	else if (s[i] == 'x')
		return (ft_hexanbr(va_arg(lst, unsigned int), "0123456789abcdef"));
	else if (s[i] == 'X')
		return (ft_hexanbr(va_arg(lst, unsigned int), "0123456789ABCDEF"));
	return (count);
}
