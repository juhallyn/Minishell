/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:19:26 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/01 15:40:04 by juhallyn         ###   ########.fr       */
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

char			*find_env(char **env, char *var_name);
char			*path_command(char *command, char *env_path);
void			ft_strsplit_del(char ***tab);
void			process(char **env, char *line);
char			*parse_line(char *line);
char			*join(char *command_path, char *env_path, char *command);
void			ft_error(char *cmd);

#endif
