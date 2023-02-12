/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:01:45 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 17:26:01 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	empty_arg(char **av)
{
	int	i;
	int	j;
	int	s;

	i = 2;
	j = 0;
	s = 0;
	while (i < 4)
	{
		while (av[i][j] != '\0')
		{
			if (av[i][j] == ' ')
				s++;
			if (s == (int)ft_strlen(av[i]) + 1)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	pars_it(int ac, char **av, t_vars *vars, int *fd)
{
	int	r;

	if (ac != 5)
	{
		ft_putstr_fd("The number of arguments is incorrect\n", 1);
		return (1);
	}
	r = check_exist(av, 1, vars);
	pars_it_end(av, vars);
	if (empty_arg(av) == 1)
		ft_error(vars, 4, " ");
	vars->cmd1 = ft_split(av[2], ' ');
	vars->cmd2 = ft_split(av[3], ' ');
	if ((vars->cmd1 == NULL || av[2][0] == '\0')
		&& (vars->cmd2 == NULL || av[3][0] == '\0'))
		ft_error(vars, 4, " ");
	if (r == 0)
	{
		if (pipe(fd) == -1)
			return (ft_putstr_fd("bash: ", 2), perror("pipe_fd"), 1);
	}
	else
		ft_error(vars, 5, " ");
	return (0);
}

int	pars_it_end(char **av, t_vars *vars)
{	
	int	r;

	r = 0;
	if (av[2][0] == '.' && av[2][1] == '/')
		r = r + check_exist(av, 2, vars);
	if (av[3][0] == '.' && av[3][1] == '/')
		r = r + check_exist(av, 3, vars);
	return (r);
}

int	check_exist(char **av, int i, t_vars *vars)
{
	char	*tmp;
	int		file;

	if (i == 2 || i == 3)
	{
		tmp = ft_substr(av[i], 2, (ft_strlen(av[i]) - 2));
		file = open(tmp, O_RDONLY);
		free(tmp);
	}
	if (i == 1)
		file = open(av[i], O_RDONLY);
	if (file == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(av[i]);
		vars->ck = i + vars->ck;
		return (1);
	}
	if (file != -1)
		close(file);
	return (0);
}
