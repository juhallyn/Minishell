/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:19:26 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/08 15:26:04 by juhallyn         ###   ########.fr       */
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

void			process(char **env, char *line);
char			*path_command(char *command, char *env_path);

/*
**	--	environement vars --
**		--> env.c
*/

char			*find_env(char **env, char *var_name);
char			**env_cpy(char **env);

/*
**	--	builtins functions --
**		--> builtins.c
*/

t_bool			is_builtins(char *cmd);
void			exec_builtins(char **cmd, char **env);

/*
**	--	error functions --
**		--> error.c
*/

void			print_error(char *cmd, char *error, char *file);
int				check_permission(char *cmd, char *file_name, char cmd_permissions);
t_bool			permission_bool(struct stat *buff, char permission);

/*
**	--	check alias --
**		--> alias.c
*/

// char			*replace_special_char(char *path, int i, char *var);
// char			*check_alias(char *src, char **path, char **env);
void			check_alias(char *src, char **path, char **env);

/*
**	--	Useless functions --
**		--> tools.c
*/

void			ft_error(char *cmd);
void			ft_strsplit_del(char ***tab);
char			*join(char *command_path, char *env_path, char *command);
char			*parse_line(char *line);
char			*creat_path(char *argv, char *d_name);

#endif
