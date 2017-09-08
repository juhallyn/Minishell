/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/08 15:25:07 by juhallyn         ###   ########.fr       */
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
		{
			ft_strsplit_del(&builtins_list);
			return (true);
		}
		i++;
	}
	ft_strsplit_del(&builtins_list);
	return (false);
}

void		exec_builtins(char **cmd, char **env)
{
	char	*home;
	char	*path;

	path = NULL;
	home = find_env(env, "HOME");
	if (ft_strcmp(cmd[0], "cd") == 0)
	{
		if (cmd[1])
		{
			check_alias(cmd[1], &path, env);
			if (chdir(path) == -1)
				check_permission(cmd[0], path, 'x');
		}
		else
		{
			if (chdir(home) == -1)
				check_permission(cmd[0], cmd[1], 'x');
		}
	}
	ft_strdel(&path);
}
