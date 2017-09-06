/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:37:00 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/06 17:27:37 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static char		*cmp_string_env(char *var_name)
{
	char	*find_name;

	find_name = ft_strjoin(var_name, "=");
	return (find_name);
}

char			**env_cpy(char **env)
{
	int		i;
	char	**my_env;

	i = 0;
	my_env = NULL;
	while (env[i])
		i++;
	my_env = (char**)malloc(sizeof(char*) * i + 1);
	if (!my_env)
		exit(-1);
	i = 0;
	while (env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

char			*find_env(char **env, char *var_name)
{
	char	*find;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if ((find = cmp_string_env(var_name)))
		len = ft_strlen(find);
	while (env[i])
	{
		if (ft_strncmp(find, env[i], len) == 0)
		{
			ft_strdel(&find);
			return (&env[i][len]);
		}
		i++;
	}
	ft_strdel(&find);
	return (NULL);
}
