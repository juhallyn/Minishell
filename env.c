/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:37:00 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/31 17:01:20 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static char		*cmp_string_env(char *var_name)
{
	char	*find_name;

	find_name = ft_strnew(ft_strlen(var_name + 1));
	find_name = ft_strcpy(find_name, var_name);
	find_name = ft_strcat(find_name, "=");
	return (find_name);
}

char			*find_env(char **env, char *var_name)
{
	char	*find;
	int		i;

	find = cmp_string_env(var_name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strlen(find)) == 0)
			return (&env[i][ft_strlen(find)]);
		i++;
	}
	return (NULL);
}
