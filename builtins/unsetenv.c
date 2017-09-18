/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:58:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/18 11:21:19 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**delete_variable(char *name, char **env)
{
	char	**new_env;
	int		i;
	int		j;

	j = 0;
	i = ft_arraylen(env) + 1;
	new_env = (char**)malloc(sizeof(char*) * (i - 1));
	if (!new_env)
		exit(-1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(name, env[i], ft_strlen(name)) == 0)
			i++;
		else
		{
			new_env[j] = ft_strdup(env[i]);
			j++;
			i++;
		}
	}
	new_env[j] = NULL;
	return (new_env);
}

void			ft_unsetenv(char *name, char ***env, int nb_arg)
{
	char	**tmp;

	tmp = *env;
	*env = delete_variable(name, *env);
	ft_arraydel(&tmp);
	tmp = NULL;
}

// ft_putendl(*env[i]);
// if (ft_strncmp(name, *env[i], ft_strlen(name)) == 0)
// 	i++;
// else
// {
// 	new_env[j] = ft_strdup(*env[i]);
// 	j++;
// }
// i++;



// char	**new_env;
// int		env_len;
// int		i;
// int		j;
//
// ft_putendl(name);
// i = 0;
// j = 0;
// // env_len = ft_arraylen(*env) + 1;
// // new_env = (char**)malloc(sizeof(char*) * (env_len - 1));
// // if (!new_env)
// 	// exit(-1);
// while (env[i])
// {
// 	ft_putendl(env[i]);
// 	i++;
// }
// // new_env[j] = NULL;
// // ft_arraydel(env);
// // *env = new_env;
