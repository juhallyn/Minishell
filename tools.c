/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:38:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/01 14:41:22 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	ft_error(char *cmd)
{
	ft_putstr_fd("minishell : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" command not found\n", 2);
	exit(-1);
}

void	ft_strsplit_del(char ***tab)
{
	int		i;
	char	**temp;

	i = 0;
	temp = *tab;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

char	*join(char *command_path, char *env_path, char *command)
{
	char	*memory;

	memory = command_path;
	command_path = ft_strjoin(env_path, "/");
	ft_strdel(&memory);
	memory = command_path;
	command_path = ft_strjoin(command_path, command);
	ft_strdel(&memory);
	return (command_path);
}

char	*parse_line(char *line)
{
	while (*line == ' ' || (*line >= '\t' && *line <= '\r'))
			(void)*line++;
	return (line);
}
