/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:05:12 by hchairi           #+#    #+#             */
/*   Updated: 2022/11/10 19:41:48 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	lst;

	count = 0;
	i = 0;
	va_start(lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_cas(lst, s, i + 1);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(lst);
	return (count);
}
