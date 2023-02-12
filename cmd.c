/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:02:43 by adelinechev       #+#    #+#             */
/*   Updated: 2023/02/12 17:19:05 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_finder(t_vars *vars, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		vars->envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (vars->envp_path)
			break ;
		i++;
	}
}

void	create_paths(t_vars *vars)
{
	int		i;
	char	*tmp;

	i = 0;
	while (vars->paths[i])
	{
		tmp = vars->paths[i];
		vars->paths[i] = ft_strjoin(vars->paths[i], "/");
		free(tmp);
		i++;
	}
}

int	check_pathcmd(t_vars *vars, char *cmd)
{
	int	i;
	int	d;

	i = 0;
	while (vars->paths[i])
	{
		vars->cmd_path = ft_strjoin(vars->paths[i], cmd);
		d = access(vars->cmd_path, F_OK | X_OK);
		if (d == 0)
			return (0);
		if (vars->cmd_path == NULL)
			ft_error(vars, 1, cmd);
		i++;
		free(vars->cmd_path);
	}
	vars->cmd_path = NULL;
	return (-1);
}

int	check_way(t_vars *vars, char *cmd)
{
	int	d;

	d = access(cmd, F_OK | X_OK);
	if (d == 0)
	{
		vars->cmd_path = cmd;
		return (0);
	}
	return (1);
}

void	end_check(t_vars *vars, int way, char *cmd)
{
	char	*tmp;

	tmp = ft_substr(vars->envp_path, 5, (ft_strlen(vars->envp_path) - 5));
	if (tmp == NULL)
		ft_error(vars, 1, cmd);
	vars->paths = ft_split(tmp, ':');
	free(tmp);
	if (vars->paths == NULL)
		ft_error(vars, 1, cmd);
	create_paths(vars);
	way = check_pathcmd(vars, cmd);
	if (way == -1)
		ft_error(vars, 1, cmd);
}
