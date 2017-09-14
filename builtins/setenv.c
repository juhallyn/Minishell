/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:46:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/14 18:04:25 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_variable(char *name, char *value, char **env)
{
	char	**new_env;
	char	*data;
	int		i;

	data = join_env_data(name, value);
	i = ft_arraylen(env) + 1;
	new_env = (char**)malloc(sizeof(char*) * i + 8);
	if (!new_env)
		exit(-1);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = data;
	new_env[i + 1] = NULL;
	return (new_env);
}

void			ft_setenv(char *name, char *value, char ***env, int nb_arg)
{
	char	**tmp;

	if (nb_arg > 2)
		ft_putendl_fd("setenv : Too many arguments.", 2);
	if (nb_arg == 0)
		print_env(*env);
	else if (nb_arg == 2)
	{
		if (!(find_env(*env, name)))
		{
			tmp = *env;
			*env = add_variable(name, value, *env);
			ft_arraydel(&tmp);
			tmp = NULL;
		}
	}
}
