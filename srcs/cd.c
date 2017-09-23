/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:47:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/21 16:50:15 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		to_home(char ***env, char *old_pwd)
{
	char	*home;

	home = find_env(*env, "HOME");
	if (check_permission("cd", home, 'x') != -1)
	{
		chdir(home);
		if (old_pwd)
			ft_setenv("OLDPWD", old_pwd, env, 2);
		ft_setenv("PWD", home, env, 2);
	}
	if (home)
		ft_strdel(&home);
}

void			change_directory(char *argv, char ***env)
{
	char	*old_pwd;
	char	buff[4096 + 1];

	old_pwd = find_env(*env, "PWD");
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
		to_home(env, old_pwd);
	if (old_pwd)
		ft_strdel(&old_pwd);
}
