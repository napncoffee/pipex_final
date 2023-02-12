/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:11:37 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:55:40 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*poss;
	char		*posd;

	poss = src;
	posd = dest;
	if ((posd != NULL) && (poss != NULL))
	{
		while (n--)
		{
			*posd = *poss;
			poss++;
			posd++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char src[24] = "Bonjour ou bonsoir";
	char dest[32] = {0};
	ft_memcpy(dest, src, 12);
	printf("%s", dest);	
}*/
/*
recopie a l'adresse de la dest la suite de longueur 
n octets debutant a ladresse src
il faut que src-dest >= n
*/
