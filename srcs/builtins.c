/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/19 18:01:49 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		is_builtins(char *cmd)
{
	char	*builtins;
	char	**builtins_list;
	int		i;

	i = 0;
	builtins = "cd,echo,exit,setenv,unsetenv,env";
	builtins_list = ft_strsplit(builtins, ',');
	while (builtins_list[i])
	{
		if (ft_strcmp(builtins_list[i], cmd) == 0)
		{
			ft_arraydel(&builtins_list);
			return (true);
		}
		i++;
	}
	ft_arraydel(&builtins_list);
	return (false);
}

void		exec_builtins(char **cmd, char ***env)
{
	int		nb_arg;

	nb_arg = count_arg_cmd(cmd);
	if (ft_strcmp(cmd[0], "cd") == 0)
		change_directory(cmd[1], env);
	if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		if (!cmd[1])
			print_env(*env);
		if (cmd[1])
			ft_setenv(cmd[1], cmd[2], env, nb_arg);
	}
	if (ft_strcmp(cmd[0], "unsetenv") == 0)
	{
		if (!cmd[1])
			ft_putendl_fd("unsetenv: Too few arguments.", 2);
		else
			ft_unsetenv(cmd, env);
	}
	if (ft_strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd, *env);
	if (ft_strcmp(cmd[0], "env") == 0)
		print_env(*env);
	if (ft_strcmp(cmd[0], "exit") == 0)
		exit(0);
}
