/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:12:17 by achevala          #+#    #+#             */
/*   Updated: 2023/01/26 18:14:41 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;
	char	*tofind;

	src = (char *) big;
	tofind = (char *) little;
	i = 0;
	if (little[0] == '\0')
		return (src);
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] == tofind[j])
		{	
			j++;
			if (tofind[j] == '\0' && (i + j <= len))
				return (&src[i]);
		}
		i++;
	}	
	return (0);
}
/*
int	main()
{
	const char *largestring = "12345678";
	const char *smallstring = "34";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 8);
	printf("%s", ptr);
}
*/