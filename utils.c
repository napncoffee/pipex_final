/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:56:35 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 16:18:41 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	var_init(t_vars *vars, char **envp)
{
	vars->envp_path = NULL;
	vars->paths = NULL;
	vars->cmd_path = NULL;
	vars->pid1 = -1;
	vars->pid2 = -1;
	vars->status_code = 0;
	vars->file1 = -1;
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;
	vars->file2 = -1;
	vars->ck = 0;
	vars->env = envp;
	return (0);
}
