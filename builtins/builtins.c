/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/12 15:26:20 by juhallyn         ###   ########.fr       */
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

void		exec_builtins(char **cmd, char ***env)
{
	char	*home;
	char	*path;
	int		nb_arg;

	nb_arg = count_arg_cmd(cmd);
	if (nb_arg == 0)
	{
		cmd[1] = NULL;
		cmd[2] = NULL;
	}
	if (ft_strcmp(cmd[0], "cd") == 0)
		change_directory(cmd[1], *env);
	if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		ft_setenv(cmd[1], cmd[2], env, nb_arg);
		print_env(*env);
	}
}
