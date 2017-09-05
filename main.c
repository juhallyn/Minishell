/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:18:37 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/05 18:14:05 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	*line;
	char	**my_env;
	(void)argc;
	(void)argv;
	int i = 0;

	my_env = env_cpy(env);
	while (42)
	{
		ft_putstr("†> ");
		get_next_line(0, &line);
		process(env, line);
	}
	return (0);
}
