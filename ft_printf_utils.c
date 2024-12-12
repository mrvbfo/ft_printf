/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukfe <mbuyukfe@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:36:23 by mbuyukfe          #+#    #+#             */
/*   Updated: 2024/11/30 11:36:23 by mbuyukfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int number)
{
	long	n;
	int		len;
	int		temp;

	len = 0;
	n = number;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		temp = ft_int(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_uint(unsigned int number)
{
	int	len;
	int	temp;

	len = 0;
	if (number >= 10)
	{
		temp = ft_uint(number / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_puthex(unsigned int number, char c)
{
	int	len;
	int	temp;

	len = 0;
	if (number >= 16)
	{
		temp = ft_puthex(number / 16, c);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
			return (-1);
	}
	if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[number % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

static int	ft_convert_to_hex(unsigned long number)
{
	int	len;
	int	temp;

	len = 0;
	if (number >= 16)
	{
		temp = ft_convert_to_hex(number / 16);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putptr(unsigned long number)
{
	int		len;
	int		temp;

	if (number == 0)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	temp = ft_convert_to_hex(number);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
