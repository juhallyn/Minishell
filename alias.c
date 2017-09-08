/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:02:40 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/08 16:30:38 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_special_char(char *src, size_t i, char *var)
{
	char	*path;
	size_t	len;

	len = (ft_strlen(src) -1) + ft_strlen(var);
	path = ft_strnew(len);
	path = ft_strncpy(path, src, i);
	path = ft_strncat(path, var, ft_strlen(var));
	ft_putendl(path);
	return (path);
}

void	check_alias(char *src, char **path, char **env)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '~')
			*path = replace_special_char(src, i, find_env(env, "HOME"));
		i++;
		break;
	}
}
