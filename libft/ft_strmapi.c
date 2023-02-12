/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:16:55 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 12:32:12 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*strf;

	if (s == NULL || !f)
		return (NULL);
	strf = (char *)malloc(sizeof(*strf) * (ft_strlen(s) + 1));
	if (!strf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strf[i] = f(i, s[i]);
		i++;
	}
	strf[i] = '\0';
	return (strf);
}
/*
s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.
Valeur de retour : La chaîne de caractères résultant des applications
successives de ’f’.OU Retourne NULL si l’allocation échoue
Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères passée en argument pour créer
une nouvelle chaîne de caractères (avec malloc(3))
résultant des applications successives de ’f’.*/
