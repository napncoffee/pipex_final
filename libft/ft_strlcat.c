/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:08:18 by achevala          #+#    #+#             */
/*   Updated: 2022/06/07 20:30:46 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		n;
	char		*tdst;
	const char	*tsrc;

	n = size;
	tdst = dst;
	tsrc = src;
	while (*tdst && n-- != 0)
		tdst++;
	dst_len = tdst - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(src));
	while (*tsrc)
	{
		if (n != 1)
		{
			*tdst++ = *tsrc;
			n--;
		}
		tsrc++;
	}
	*tdst = '\0';
	return (dst_len + ft_strlen(src));
}
