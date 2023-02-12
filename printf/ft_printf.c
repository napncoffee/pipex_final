/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:47:48 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:40:12 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putall(char c, va_list arg)
{
	int	l;

	if (c == 'c')
		l = ft_putchar((unsigned char)va_arg(arg, int));
	if (c == 's')
		l = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		l = ft_putptr(va_arg(arg, unsigned long long));
	if (c == 'd' || c == 'i')
		l = ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		l = ft_putnbru(va_arg(arg, unsigned int));
	if (c == 'x')
		l = ft_puthexad(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		l = ft_puthexad(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (c == '%')
	{
		write(1, "%", 1);
		l = 1;
	}
	return (l);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			j += 2;
			l = ft_putall(str[i], arg) + l;
			i++;
		}
		else
			ft_putchar(str[i++]);
	}
	va_end(arg);
	return (i + l - j);
}
/*
int main(void)
{
    int c;
    int v;
        
    c = ft_printf(" %p %p ", NULL, NULL);
    printf("%d \n\n", c);
    v = printf(" %p %p ", NULL, NULL);
    printf("v = %d", v);
}*/
/*inclure stdarg.h dans son programme ;
déclarer une variable de type va_list ;
l'initialiser avec va_start() ;
lire les arguments un par un avec va_arg() ;
terminer avec va_end().*/ 