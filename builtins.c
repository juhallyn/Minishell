/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/06 19:06:49 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		is_builtins(char *cmd)
{
	char	*builtins;
	char	**builtins_list;
	int		i;

	i = 0;
	builtins = "cd,echo,exit,setenv,unsetenv";
	builtins_list = ft_strsplit(builtins, ',');
	while (builtins_list[i])
	{
		if (ft_strcmp(builtins_list[i], cmd) == 0)
			return (true);
		i++;
	}
	return (false);
}

void		exec_builtins(char **cmd, char **env)
{
	char	*home;

	home = find_env(env, "HOME");
	if (ft_strcmp(cmd[0], "cd") == 0)
	{
		if (cmd[1])
			chdir(cmd[1]);
		else
		{
			
			chdir(home);
		}
	}
}
