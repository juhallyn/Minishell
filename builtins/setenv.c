/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:46:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/11 16:58:36 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**add_env_var(char *name, char *value, char **env)
{
	int		len;
	char	**new_env;

	while (env[len])
		len++;
	new_env = (char**)malloc(sizeof(char*) * len + 2);

}

// static char		**modif_env_var(char *name, char *value, char **env)
// {
//
// }

char			**ft_setenv(char *name, char *value, char **env, int nb_arg)
{
	char	**new_env;

	new_env = env;
	if (nb_arg == 0)
		print_env(env);
	if (nb_arg > 3)
		ft_putendl_fd("setenv : Too many arguments.", 2);
	if (!find_env(env, name))
	{

	}
	else
	{

	}
	return (new_env);
}
