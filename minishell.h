/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:19:26 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/31 19:47:15 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <dirent.h>

typedef	enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

char			*find_env(char **env, char *var_name);
char			*path_command(char *command, char *env_path);

#endif
