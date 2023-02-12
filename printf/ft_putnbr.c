/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:42:15 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:43:45 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		i = 1;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10 + '0'));
	return (ft_sizedecimal(n) + i);
}

int	ft_sizedecimal(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{	
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbru(unsigned int n)
{
	if (n > 9)
		ft_putnbru(n / 10);
	ft_putchar((n % 10 + '0'));
	return (ft_sizedecimal(n));
}
