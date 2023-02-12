/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:27:16 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:54:34 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pos;

	pos = s;
	while (n--)
	{
		*pos = '\0';
		pos++;
	}
}
/*
int	main(void)
{
	char	str[55] = "la tomate est um legume";
	ft_bzero(str + 10, 4);
	printf("%s", str);
}
*/
/*The  bzero()  function  erases  the  data in the n bytes of the 
memory starting at the location pointed to by s, by writing zeros
       (bytes containing '\0') to that area.
*/
