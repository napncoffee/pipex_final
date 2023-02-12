/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:07 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 12:26:39 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nb(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	is_signe(int n)
{
	int	signe;

	signe = 0;
	if (n < 0)
		signe++;
	return (signe);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	str = malloc(sizeof(char) * (count_nb(nb) + is_signe(n) + 1));
	if (!str)
		return (NULL);
	i = count_nb(nb) + is_signe(n);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while ((nb || nb == 0) && i > 0)
	{
		i--;
		str[i] = nb % 10 + '0';
		nb = (nb - (nb % 10)) / 10;
	}
	if (is_signe(n) == 1)
		str[0] = '-';
	return (str);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(0));
	return 0;
}
*/
/*
n: L’entier à convertir.
Valeur de retour : La chaîne de caractères représentant l’entier.
NULL si l’allocation échoue.
Alloue avec malloc et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.*/
