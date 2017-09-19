/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:57:22 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/19 16:52:23 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void		env_var(char *str, char **env)
{
	char	*env_var;

	env_var = find_env(env, str + 1);
	ft_putstr(env_var);
}

void					ft_echo(char **args, char **env)
{
	size_t		i;
	size_t		j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '$')
			{
				env_var(args[i] + j, env);
				j = ft_strlen(args[i]);
			}
			ft_putchar(args[i][j]);
			j++;
		}
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
