/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:38:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/08 11:22:29 by juhallyn         ###   ########.fr       */
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

char	*creat_path(char *argv, char *d_name)
{
	char    *path;
	size_t  len;

	if (!argv || !d_name)
		return (NULL);
	len = ft_strlen(argv) + 2 + ft_strlen(d_name);
	path = ft_strnew(len);
	path = ft_strcpy(path, argv);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, d_name);
	return (path);
}

char	*parse_line(char *line)
{
	while (*line == ' ' || (*line >= '\t' && *line <= '\r'))
	(void)*line++;
	return (line);
}
