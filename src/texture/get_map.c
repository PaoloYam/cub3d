/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/17 15:45:52 by tbrulhar         ###   ########.fr       */
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

	while (i < line)
	{
		info->info[i] = get_next_line(fd);
		if (!only_space(info->info[i]))
			break ;
		i++;
	}
	info->mapi.map = malloc((line - i - 1) * sizeof(*(info->mapi.map)));
	if (!info->mapi.map)
		return ;
		info->mapi.h = line - i - 1;
	j = 0;
	while (i < line - 1)
	{	
		info->mapi.map[j] = ft_strdup(info->info[i]);
		info->info[i + 1] = get_next_line(fd);
		i++;
		j++;
	}
}
