/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:18:37 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/14 16:26:49 by jle-quel         ###   ########.fr       */
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
	my_env = env_cpy(env);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		process(&my_env, line);
		ft_strdel(&line);
	}
	return (0);
}
