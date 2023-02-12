/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:01:48 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 17:35:04 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(t_vars *vars, int *fd, char **envp, char **av)
{
	vars->file1 = open(av[1], O_RDONLY);
	if (vars->file1 == -1)
		ft_error(vars, 2, av[1]);
	dup2(vars->file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(vars->file1);
	check_cmd(vars, vars->cmd1[0], 1, av);
	execve(vars->cmd_path, vars->cmd1, envp);
	strerror(errno);
}

void	child_two(t_vars *vars, int *fd, char **envp, char **av)
{
	vars->file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (vars->file2 == -1)
		ft_error(vars, 2, av[4]);
	dup2(fd[0], STDIN_FILENO);
	dup2(vars->file2, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(vars->file2);
	check_cmd(vars, vars->cmd2[0], 2, av);
	execve(vars->cmd_path, vars->cmd2, envp);
	strerror(errno);
}

int	check_cmd(t_vars *vars, char *cmd, int c, char **av)
{
	int	way;

	if (cmd == NULL || av[c + 1][0] == '\0')
		ft_error(vars, 1, " ");
	if ((c == 1 && (vars->ck == 2 || vars->ck == 5))
		|| (c == 2 && (vars->ck == 3 || vars->ck == 5)))
		ft_error(vars, 5, " ");
	if (cmd[0] == '.' && cmd[1] == '\0')
		ft_error(vars, 6, ".");
	path_finder(vars, vars->env);
	way = check_way(vars, cmd);
	if (way == 0)
		return (0);
	if (vars->envp_path != NULL)
		end_check(vars, way, cmd);
	if (vars->envp_path == NULL)
		ft_error(vars, 1, cmd);
	return (0);
}
