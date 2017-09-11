/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:47:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/11 13:54:20 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_directory(char *argv, char **env)
{
	char	*home;

	home = find_env(env, "HOME");
	if (argv)
	{
		if (check_permission("cd" ,argv, 'x') != -1)
			chdir(argv);
	}
	else
	{
		if (check_permission("cd", home, 'x') != -1)
			chdir(home);
	}
}
