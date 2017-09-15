/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:58:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/15 16:39:33 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_init(char **env, int env_len, int new_size)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_env = NULL;
	new_env = (char**)malloc(sizeof(char*) * (new_size + 1));
	if (!new_env)
		exit(-1);
	while (i < env_len)
	{
		if (!env[i])
			;
		else
		{
			new_env[j] = ft_strdup(env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

static char		**realloc_without_null(char **env, int env_len)
{
	int		i;
	int		new_size;

	i = 0;
	new_size = 0;
	while (i < env_len)
	{
		if (!env[i])
			;
		else
			new_size++;
	}
	return (ft_init(env, env_len, new_size));
}

char			**ft_unsetenv(char **args, char ***env, int nb_arg)
{
	int		i;
	int		j;
	int		env_len;
	char	**new_env;

	new_env = NULL;
	env_len = ft_arraylen(*env);
	printf("len : %d\n", env_len);
	i = 0;
	j = 0;
	while (args[j])
	{
		ft_putendl(args[j]);
		j++;
	}
	while (i < env_len)
	{
		j = 1;
		while (args[j])
		{
			if (ft_strncmp(args[j], *env[i], ft_strlen(args[j])) == 0)
			{
				// ft_putendl(args[j]);
				// free(*env[i]);
				// *env[i] = NULL;
			}
			j++;
		}
		// ft_putendl(*env[i]);
		i++;
	}
	// new_env = realloc_without_null(*env, env_len);
	// return (new_env);
}
