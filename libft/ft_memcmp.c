/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:51:13 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:55:02 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1 ;
	unsigned char	*p2 ;
	int				valeur;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	valeur = 0;
	while (n > 0)
	{
		if (*p1 != *p2)
		{
			valeur = (*p1 - *p2);
			return (valeur);
		}
		p2++;
		p1++;
		n--;
	}
	return (valeur);
}
/*
int	main(void)
{
	const char str1[24] = "444";
	const char str2[23] = "4424o";
	printf("%d", ft_memcmp(str1, str2, 4));
}*/
/*
effectue une comparaison lexicographique de deux suites 
d'octets de meme longueur en utilisant les memes regeles que strcmp.
*/
