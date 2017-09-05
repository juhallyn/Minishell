/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:19:26 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/05 18:15:14 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/wait.h>

typedef	enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef struct		s_env
{
	char			*data;
	struct 	s_env	*next;
}					t_env;

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
**	--	Useless functions --
**		--> tools.c
*/

void			ft_error(char *cmd);
void			ft_strsplit_del(char ***tab);
char			*join(char *command_path, char *env_path, char *command);
char			*parse_line(char *line);

#endif
