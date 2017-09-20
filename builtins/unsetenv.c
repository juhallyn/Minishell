/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:58:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/20 16:47:27 by juhallyn         ###   ########.fr       */
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

void			ft_unsetenv(char **args, char ***env)
{
	char	**tmp;
	int		i;

	i = 1;
	while (args[i])
	{
		tmp = *env;
		*env = delete_variable(args[i], *env);
		i++;
		ft_arraydel(&tmp);
		tmp = NULL;
	}
}
