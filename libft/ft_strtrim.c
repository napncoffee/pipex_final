/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:28:22 by achevala          #+#    #+#             */
/*   Updated: 2022/06/16 11:57:40 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_start(const char *s1, char const *set)
{
	int	s;

	s = 0;
	while (ft_check(s1[s], set) == 1)
		s++;
	return (s);
}

static int	check_end(const char *s1, char const *set)
{	
	int	e;

	e = ft_strlen(s1) - 1;
	while ((ft_check(s1[e], set) == 1))
		e--;
	return (e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s;
	size_t		e;
	size_t		i;
	char		*str;

	s = check_start(s1, set);
	e = check_end(s1, set);
	i = 0;
	if (s == ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = 0;
		return (str);
	}
	str = malloc(sizeof(char) * (e - s + 2));
	if (!str)
		return (NULL);
	while (s <= e)
		str[i++] = s1[s++];
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	const char	*s1 = "";
	const char 	*set = "!?,";

	printf("%s", ft_strtrim(s1, set));
}*/
