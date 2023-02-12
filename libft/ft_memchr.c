/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:52 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:54:57 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pos ;
	unsigned char	*same ;

	pos = (unsigned char *) s;
	same = NULL;
	while ((s != NULL) && n--)
	{
		if (*pos == (unsigned char) c)
		{
			same = pos;
			return (same);
		}
		pos++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char str[24] = "Bonjour ou bonsoir";
	char* ptr = ft_memchr(str, 'j', sizeof(str));
	printf("%s", ptr);
}*/
/*memchr permet de chercher la premiere 
occurrence d'une valeur donnee dans une suite d'octets.*/
