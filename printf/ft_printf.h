/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:19:49 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:42:37 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putall(char c, va_list arg);
int		ft_putchar(unsigned char c);
void	ft_puthex(unsigned int n, char *base);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_size(unsigned int n);
int		ft_putptr(unsigned long long n);
int		ft_sizedecimal(long int n);
int		ft_putnbru(unsigned int n);
int		ft_puthexad(unsigned int n, char *base);
void	ft_puthexaptr(unsigned long long n, char *base);
int		ft_sizeptr(unsigned long long n);

#endif