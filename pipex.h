/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevala <achevala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:46:10 by achevala          #+#    #+#             */
/*   Updated: 2023/02/12 17:04:12 by achevala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_vars
{
	char	*envp_path;
	char	**paths;
	char	*cmd_path;
	pid_t	pid1;
	pid_t	pid2;
	int		status_code;
	int		file1;
	int		file2;
	char	**cmd1;
	char	**cmd2;
	int		ck;
	char	**env;
}			t_vars;

/* main.c*/
void	end_main(int *fd, t_vars *vars);
int		main(int ac, char *av[], char **env);

/* utils.c */
int		var_init(t_vars *vars, char **envp);

/* parsing.c */
int		empty_arg(char **av);
int		pars_it(int ac, char **av, t_vars *vars, int *fd);
int		pars_it_end(char **av, t_vars *vars);
int		check_exist(char **av, int i, t_vars *vars);

/* pipex.c */
void	child_one(t_vars *vars, int *fd, char **envp, char **av);
void	child_two(t_vars *vars, int *fd, char **envp, char **av);
int		check_cmd(t_vars *vars, char *cmd, int c, char **av);

/* error.c */
void	free_vars(t_vars *vars);
void	ft_error(t_vars *vars, int i, char *cmd);
void	end_error(t_vars *vars);

/* cmd.c */
void	path_finder(t_vars *vars, char **envp);
void	create_paths(t_vars *vars);
void	end_check(t_vars *vars, int way, char *cmd);
int		check_pathcmd(t_vars *vars, char *cmd);
int		check_way(t_vars *vars, char *cmd);

#endif