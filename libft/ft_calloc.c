/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:14:00 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:44:30 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*apl;

	if (size && size * nmemb / size != nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	apl = malloc(nmemb * size);
	if (!apl)
		return (NULL);
	ft_bzero(apl, nmemb * size);
	return (apl);
}
/*
int	main(void)
{
	ft_calloc(10, 4);
}*/
