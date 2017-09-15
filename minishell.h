/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:19:26 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/15 16:34:48 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef	enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

/*
**	--	check and process functions --
**		--> command.c
*/

void			process(char ***env, char *line);
char			*path_command(char *command, char *env_path);

/*
**	--	environement vars --
**		--> env.c
*/

char			*find_env(char **env, char *var_name);
char			**env_cpy(char **env);

/*
**	--	run builtins functions --
**		--> builtins.c
**/

t_bool			is_builtins(char *cmd);
void			exec_builtins(char **cmd, char ***env);

/*
**	all builtins command are in "builtins"
**		folder with $builtin_name.c
*/

void			change_directory(char *argv, char **env);
void			ft_setenv(char *name, char *value, char ***env, int nb_arg);
char			**add_variable(char *name, char *value, char **env);
char			**modif_variable(char *name, char *value, char **env);
// char			**ft_unsetenv(char **args, char ***env);
char			**ft_unsetenv(char **args, char ***env, int nb_arg);
// char			**ft_unsetenv(char **args, char **env);

/*
**	--	error functions --
**		--> error.c
*/

void			print_error(char *cmd, char *error, char *file);
int				check_permission(char *cmd, char *file_name, char cmd_permissions);
t_bool			permission_bool(struct stat *buff, char permission);

/*
**	--	Useless functions --
**		--> tools.c
*/

void			ft_error(char *cmd);
void			ft_strsplit_del(char ***tab);
char			*join(char *command_path, char *env_path, char *command);
char			*parse_line(char *line);
char			*creat_path(char *argv, char *d_name);

/*
**	--	Useless functions --
**		--> tools2.c
*/

int				count_arg_cmd(char **cmd);
void			print_env(char **env);
char			*join_env_data(char *name, char *value);

#endif
