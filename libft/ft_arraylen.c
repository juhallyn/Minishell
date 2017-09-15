/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:09:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/14 17:09:36 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t			ft_arraylen(char **argv)
{
	size_t	index;

	index = 0;
	while (argv[index])
		index++;
	return (index);
}
