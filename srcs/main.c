/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:18:37 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/21 15:26:35 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	**my_env;
	char	*line;

	(void)argc;
	(void)argv;
	my_env = NULL;
	line = NULL;
	if (*env)
		my_env = env_cpy(env);
	while (42)
	{
		ft_putstr("\x1B[32m$> \x1B[0m");
		get_next_line(0, &line);
		line = escape_chars(line);
		process(&my_env, line);
		ft_strdel(&line);
	}
	return (0);
}
