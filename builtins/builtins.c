/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/14 19:42:54 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_arraydel(char ***array);


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
	char	*home;
	char	*path;
	int		nb_arg;

	nb_arg = count_arg_cmd(cmd);
	if (nb_arg == 0)
	{
		cmd[1] = NULL;
		// cmd[2] = NULL;
	}
	if (ft_strcmp(cmd[0], "cd") == 0)
		change_directory(cmd[1], *env);
	if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		if (!cmd[1])
			print_env(*env);
		ft_setenv(cmd[1], cmd[2], env, nb_arg);
	}
}
