/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 11:52:05 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	only_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
			return (0);
		i++;
	}
	return (1);
}

void	load_map(int i, int line, int fd, t_info *info)
{
	int		j;

	i++;
	while (i < line)
	{
		info->info[i] = get_next_line(fd);
		if (!only_space(info->info[i]))
			break ;
		i++;
	}
	info->mapi.map = malloc((line - i) * sizeof(*(info->mapi.map)));
	if (!info->mapi.map)
		return ;
	info->mapi.h = line - i;
	j = 0;
	while (i < line)
	{	
		info->mapi.map[j] = ft_strdup(info->info[i]);
		info->info[i + 1] = get_next_line(fd);
		i++;
		j++;
	}
}
