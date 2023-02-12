/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:43:50 by achevala          #+#    #+#             */
/*   Updated: 2022/11/09 22:08:22 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pos;

	pos = s;
	while (n--)
		*pos++ = (unsigned char)c;
	return (s);
}
/*
int	main(void)
{
	char str[24] = "Bonjour ou bonsoir";
	
	ft_memset(str + 2, 'a', 5);
	printf("%s", str);
}*/
/*
memset permet d'initialiser chacun des octets 
d'une suite donnee avec une valeur determinee 

*s __> adresse du premier octet a initialiser
c __> valeur qui, apres conversion en unsigned char, 
sera utilisee pour initialiser chaque octet
n __> nombre d'octets a initialiser 
valeur de retour __> adresse du premier octet a initialiser 
*/
