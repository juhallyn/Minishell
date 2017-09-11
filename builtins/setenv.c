/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:46:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/11 18:19:38 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**add_env_var(char *name, char *value, char **env)
{
	int		len;
	int		i;
	char	**new_env;
	char	*data;

	data = join_env_data(name, value);
	i = 0;
	len = 0;
	while (env[len])
		len++;
	new_env = (char**)malloc(sizeof(char*) * len + 2);
	while (i < len)
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i++] = data;
	new_env[i++] = NULL;
	ft_strsplit_del(&env);
	ft_strdel(&data);
	// print_env(new_env);
	return (new_env);
}

// static char		**modif_env_var(char *name, char *value, char **env)
// {
//
// }

char			**ft_setenv(char *name, char *value, char **env, int nb_arg)
{
	char	**new_env;

	new_env = env;
	if (nb_arg > 2)
		ft_putendl_fd("setenv : Too many arguments.", 2);
	if (nb_arg == 0)
		print_env(env);
	else if (nb_arg == 2)
	{
		if (!find_env(env, name))
			new_env = add_env_var(name, value, env);
	}
	return (new_env);
}
