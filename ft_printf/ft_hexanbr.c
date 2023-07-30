/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexanbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:57 by hchairi           #+#    #+#             */
/*   Updated: 2022/11/09 22:41:27 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexanbr(unsigned long int nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_putchar(base[nb]);
	else
	{
		count += ft_hexanbr(nb / 16, base);
		count += ft_hexanbr(nb % 16, base);
	}
	return (count);
}
