/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:44 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:57:21 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t maxsize)
{
	size_t	i;

	i = 0;
	if (maxsize == 0)
		return (ft_strlen(src));
	if (maxsize > 0)
	{
		while (i < maxsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(src));
	}
	return (0);
}
/*
int	main()
{
	char 	*dest;

	dest = "Hello";
	ft_strlcpy(dest, "Bonjour", 4);
}*/
