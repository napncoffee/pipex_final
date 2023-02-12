/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:24:41 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:56:29 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (src < dest)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n--)
		*d-- = *s--;
	}
	else if (src >= dest)
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[24] = "Bonjour ou bonsoir";
	char dest[32] = {0};
	ft_memmove(dest, src + 5, 12);
	printf("%s", dest);	
}*/
/*
recopie a l'adresse de la dest la suite de 
longueur n octets debutant a ladresse src
il faut que src-dest >= n
*/
