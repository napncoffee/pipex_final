/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:28:56 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:44:37 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	if (n == 0 || (void *)n == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		ft_putstr("0x");
		ft_puthexaptr(n, "0123456789abcdef");
	}
	return (ft_sizeptr(n) + 2);
}

void	ft_puthexaptr(unsigned long long n, char *base)
{	
	if (n < 16)
		ft_putchar(base[n]);
	else
	{
		ft_puthexaptr((n / 16), base);
		ft_puthexaptr(n % 16, base);
	}
}

int	ft_sizeptr(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{	
		n = n / 16;
		i++;
	}
	return (i);
}
