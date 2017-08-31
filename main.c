/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:18:37 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/31 20:16:00 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int		main(int argc, char **argv, char **env)
{
	pid_t	father;
	char	*line;
	char	**command;
	char	*env_var;

	while (42)
	{
	if ((env_var = find_env(env,  argv[1])))
	{
		path_command(argv[2], env_var);
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
