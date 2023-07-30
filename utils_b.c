/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:12:49 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/13 17:13:05 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	lennb(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*s;

	nb = n;
	len = lennb(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
	}
	if (nb == 0)
		s[0] = '0';
	s[len] = '\0';
	len--;
	while (nb)
	{
		s[len] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (s);
}
