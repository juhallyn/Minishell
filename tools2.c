/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:34:46 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/11 17:57:38 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

int		count_arg_cmd(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	return (i - 1);
}

char	*join_env_data(char *name, char *value)
{
	char	*data;
	char	*memory;

	memory = NULL;
	data = ft_strnew(ft_strlen(name) + ft_strlen(value) + 1);
	data = ft_strjoin(name, "=");
	memory = data;
	data = ft_strjoin(data, value);
	ft_strdel(&memory);
	return (data);
}
