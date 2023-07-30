/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:59:08 by hchairi           #+#    #+#             */
/*   Updated: 2022/11/09 10:53:09 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr(long int nb);
int		ft_putstr(const char *s);
int		ft_printf(const char *s, ...);
int		ft_cas(va_list lst, const char *s, int i);
int		ft_hexanbr(unsigned long int nb, char *base);

#endif
