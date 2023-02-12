/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:15:12 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 13:11:51 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
Valeur de retour Aucune
Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément.*/
