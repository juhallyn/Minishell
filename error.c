/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:00:12 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/18 11:58:46 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *cmd, char *error, char *file)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(file, 2);
}

t_bool	permission_bool(struct stat *buff, char permission)
{
	mode_t		owner;

	owner = buff->st_mode & S_IRWXU;
	if (permission == 'r')
	 	return (owner & S_IRUSR ? true : false);
	if (permission == 'w')
		return (owner & S_IWUSR ? true : false);
	if (permission == 'x')
		return (owner & S_IXUSR ? true : false);
	return (false);
}

int		check_permission(char *cmd, char *file_name, char cmd_permissions)
{
	DIR		*dir;
	struct	stat buff;

	dir = opendir(file_name);
	if (!dir)
	{
		if (lstat(file_name, &buff) != 0)
			print_error(cmd, " : no such file or directory: ", file_name);
		else
		{
			if (permission_bool(&buff, cmd_permissions) == false)
				print_error(cmd, " : permission denied: ", file_name);
		}
		return (-1);
	}
	closedir(dir);
	return (0);
}
