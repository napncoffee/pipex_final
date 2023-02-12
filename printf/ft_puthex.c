/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:12:22 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:44:45 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *base)
{	
	if (n < 16)
		ft_putchar(base[n]);
	else
	{
		ft_puthex((n / 16), base);
		ft_puthex(n % 16, base);
	}
}

int	ft_size(unsigned int n)
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

int	ft_puthexad(unsigned int n, char *base)
{
	ft_puthex(n, base);
	return (ft_size(n));
}
/*
int main(void)
{
	ft_puthex(7657, "0123456789abcdef");
}*/
