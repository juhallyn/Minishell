/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:09:36 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/06 19:10:30 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_fork(char **cmd, char *command_path, char **env)
{
	 pid_t	pid;
	 int	ret;

	 pid = fork();
	 if (pid == 0)
	 {
		 if (!command_path)
		 	ft_error(cmd[0]);
		 ret = execve(command_path, cmd, env);
		 if (ret == -1)
		 	ft_error(cmd[0]);
	 }
	 else
	 	wait(&pid);
}

void		process(char **env, char *line)
{
	char	*env_var;
	char	*command_path;
	char	**command;
	t_bool	builtins;

	command_path = NULL;
	command = ft_strsplit(parse_line(line), ' ');
	builtins = is_builtins(command[0]);
	if ((env_var = find_env(env, "PATH")))
		command_path = path_command(command[0], env_var);
	if (builtins == false)
		ft_fork(command, command_path, env);
	else
		exec_builtins(command, env);
	ft_strsplit_del(&command);
	ft_strdel(&command_path);
	ft_strdel(&line);
}

char		*path_command(char *command, char *env_path)
{
	char	**all_paths;
	char	*command_path;
	int		i;

	i = 0;
	command_path = NULL;
	if (!command)
		return (NULL);
	all_paths = ft_strsplit(env_path, ':');
	while (all_paths[i])
	{
		command_path = join(command_path, all_paths[i], command);
		if (access(command_path, F_OK) == 0)
		{
			ft_strsplit_del(&all_paths);
			return (command_path);
		}
		i++;
	}
	ft_strdel(&command_path);
	ft_strsplit_del(&all_paths);
	return (NULL);
}
