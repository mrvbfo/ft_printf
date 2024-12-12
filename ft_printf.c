/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukfe <mbuyukfe@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:36:13 by mbuyukfe          #+#    #+#             */
/*   Updated: 2024/11/30 11:36:13 by mbuyukfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

static int	ft_format(va_list *arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*arg, unsigned long)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_uint(va_arg(*arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*arg, unsigned int), c));
	else
		return (-1);
}

static int	ft_error(va_list *arg)
{
	va_end(*arg);
	return (-1);
}

static int	handle_format(va_list *arg, const char **format)
{
	int	ret;

	(*format)++;
	if (**format == '\0')
		return (-1);
	ret = ft_format(arg, **format);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		ret;

	len = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			ret = handle_format(&arg, &format);
		else
			ret = ft_putchar(*format);
		if (ret == -1)
			return (ft_error(&arg));
		len += ret;
		format++;
	}
	va_end(arg);
	return (len);
}
