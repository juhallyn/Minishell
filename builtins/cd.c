/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:47:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/20 16:47:24 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_directory(char *argv, char ***env)
{
	char	*home;
	char	*old_pwd;
	char	buff[4096 + 1];

	old_pwd = find_env(*env, "PWD");
	home = find_env(*env, "HOME");
	if (argv)
	{
		if (check_permission("cd", argv, 'x') != -1)
		{
			chdir(argv);
			if (old_pwd)
				ft_setenv("OLDPWD", old_pwd, env, 2);
			ft_setenv("PWD", getcwd(buff, 4096), env, 2);
		}
	}
	else
	{
		if (check_permission("cd", home, 'x') != -1)
		{
			chdir(home);
			if (old_pwd)
				ft_setenv("OLDPWD", old_pwd, env, 2);
			ft_setenv("PWD", home, env, 2);
		}
	}
	if (old_pwd)
		ft_strdel(&old_pwd);
	ft_strdel(&home);
}
