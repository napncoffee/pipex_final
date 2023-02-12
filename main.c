/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:02:09 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 17:07:17 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	end_main(int *fd, t_vars *vars)
{
	close(0);
	close(1);
	close(2);
	close(fd[0]);
	close(fd[1]);
	free_vars(vars);
}

int	main(int ac, char *av[], char **env)
{
	t_vars	vars;
	int		fd[2];
	int		status;

	var_init(&vars, env);
	if (pars_it(ac, av, &vars, fd) == 1)
	{
		free_vars(&vars);
		exit(EXIT_FAILURE);
	}
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		return (perror("fork"), 1);
	if (vars.pid1 == 0)
		child_one(&vars, fd, env, av);
	vars.pid2 = fork();
	if (vars.pid2 == -1)
		return (perror("fork"), 1);
	if (vars.pid2 == 0)
		child_two(&vars, fd, env, av);
	end_main(fd, &vars);
	waitpid(vars.pid1, &status, 0);
	waitpid(vars.pid2, &status, 0);
	return (0);
}
