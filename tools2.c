/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:34:46 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/12 15:18:41 by juhallyn         ###   ########.fr       */
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
	int		len;

	len = (ft_strlen(name) + ft_strlen(value) + 1);
	data = (char*)malloc(sizeof(char) * len + 1);
	if (!data)
		exit(-1);
	data = ft_strcpy(data, name);
	data = ft_strcat(data, "=");
	data = ft_strcat(data, value);
	return (data);
}
