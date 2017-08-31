/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:09:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/31 20:01:35 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char		*create_path(char *env_path, char *command)
// {
// 	int		len;
// 	char	*command_path;
//
// 	len = ft_strlen(env_path) + 1 + ft_strlen(command_path);
// 	command_path = ft_strnew(len);
// 	command_path = ft_strcpy(command_path, env_path);
// 	command_path = ft_strcat(command_path, "/");
// 	command_path = ft_strcat(command_path, command);
// 	return (command_path);
// }

char		*path_command(char *command, char *env_path)
{
	char	**all_paths;
	int		i;
	char	*absolute_path;

	i = 0;
	all_paths = ft_strsplit(env_path, ':');
	while (all_paths[i])
	{
		absolute_path = ft_strjoin(all_paths[i], "/");
		absolute_path = ft_strjoin(absolute_path, command);
		if (access(absolute_path, F_OK) == 0)
			printf("%s is ok\n", absolute_path);
		ft_strdel(&absolute_path);
		i++;
	}
	return (NULL);
}
