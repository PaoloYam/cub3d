/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 19:58:02 by tbrulhar         ###   ########.fr       */
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

int	load_map_suite(int i, int line, int fd, t_info *info)
{
	int	j;

	j = 0;
	while (i < line)
	{
		if (info->info[i][0] != ' ' && info->info[i][0] != '\n'
			&& info->info[i][0] != '1' && info->info[i][0] != '\n')
		{
			info->info[i] = NULL;
			info->map_alloc_size = j;
			return (printf("Error: Map: No valid map at the end of file\n"));
		}
		info->mapi.map[j] = ft_strdup(info->info[i]);
		if (i + 1 <= line - 1)
			info->info[i + 1] = get_next_line(fd);
		i++;
		j++;
	}
	info->map_alloc_size = j;
	return (0);
}

int	load_map(int i, int line, int fd, t_info *info)
{
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
		return (1);
	info->mapi.h = line - i;
	if (i == line)
		info->map_alloc_size = 0;
	return (load_map_suite(i, line, fd, info));
}
