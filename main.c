/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:18:37 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/01 16:42:06 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	*line;
	pid_t	pid;
	(void)argc;
	(void)argv;

	pid = fork();
	while (42)
	{
		if (pid == 0)
		{
			wait(NULL);
			ft_putstr("$> ");
			get_next_line(0, &line);
			process(env, line);
		}
		else if (pid < 0)
			perror("minishell error");
		else
		{
			wait(&pid);
			main(argc, argv, env);
		}
	}
	return (0);
}

	// int		i = 0;
	//
	// father = fork();
	// if (father > 0)
	// 	ft_putendl("father process");
	// if (father == 0)
	// {
	// 	ft_putstr("$>");
	// 	get_next_line(0, &line);
	// 	command = ft_strsplit(line, ' ');
	// 	ft_strdel(&line);
	// 	if (execve(ft_strjoin("/bin/", command[0]), command, env) == -1)
	// 		perror("error");
	// 	ft_strsplit_del(&command);
	// }
	// return (0);
