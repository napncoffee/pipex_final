/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:07:17 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:54:29 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		sign;
	int		result;

	ptr = (char *) nptr;
	sign = 1;
	result = 0;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == ' ' )
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + *ptr - '0';
		ptr++;
	}
	return (result * sign);
}
/*
int	main()
{
	const char* nptr = "    -1213";
	printf("%d", ft_atoi(nptr));
}*/
