/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukfe <mbuyukfe@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:36:01 by mbuyukfe          #+#    #+#             */
/*   Updated: 2024/11/30 11:36:01 by mbuyukfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_int(int number);
int	ft_uint(unsigned int number);
int	ft_puthex(unsigned int number, char c);
int	ft_putptr(unsigned long number);
int	ft_putchar(char a);

#endif
