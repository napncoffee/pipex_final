/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:54:39 by achevala          #+#    #+#             */
/*   Updated: 2022/07/11 21:24:50 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	l;

	l = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[l])
	{
		ft_putchar(s[l]);
		l++;
	}
	return (l);
}
