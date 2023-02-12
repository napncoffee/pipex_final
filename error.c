/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:02:33 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 17:21:17 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_vars(t_vars *vars)
{
	if (vars->paths != NULL)
		freetab(vars->paths);
	if (vars->cmd_path != NULL)
		free(vars->cmd_path);
	if (vars->cmd1 != NULL)
	{
		freetab(vars->cmd1);
		vars->cmd1 = NULL;
	}		
	if (vars->cmd2 != NULL)
	{
		freetab(vars->cmd2);
		vars->cmd1 = NULL;
	}
}

void	ft_error(t_vars *vars, int i, char *cmd)
{
	ft_putstr_fd("bash: ", 2);
	if (i == 1 || i == -1 || i == 4)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (i == 2)
		perror(cmd);
	if (i == 3)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (i == 4)
		ft_error(vars, 1, " ");
	if (i == 6)
	{
		ft_putstr_fd(".: filename argument required\n", 2);
		ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
	}
	end_error(vars);
}

void	end_error(t_vars *vars)
{
	close(0);
	close(1);
	close(2);
	free_vars(vars);
	exit(EXIT_FAILURE);
}
