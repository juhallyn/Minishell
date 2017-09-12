/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:46:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/12 15:47:23 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_variable(char *name, char *value, char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = (char**)malloc(sizeof(char*) * i + 2);
	if (!new_env)
		exit(-1);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i++] = ft_strdup(name);
	new_env[i++] = NULL;
	// ft_strsplit_del(&env);
	return (new_env);
}

void			ft_setenv(char *name, char *value, char ***env, int nb_arg)
{
	char	**new_env;

	new_env = NULL;
	if (nb_arg > 2)
		ft_putendl_fd("setenv : Too many arguments.", 2);
	if (nb_arg == 0)
		print_env(*env);
	else if (nb_arg == 2)
	{
		if (!find_env(*env, name))
		{
			new_env = add_variable(name, value, *env);
			ft_strsplit_del(env);
			*env = new_env;
		}
	}
}
