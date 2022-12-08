/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:40:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 22:32:36 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	initialize_texture(t_info *info)
{
	info->mapi.map = NULL;
	info->texture.n_wall = NULL;
	info->texture.s_wall = NULL;
	info->texture.w_wall = NULL;
	info->texture.e_wall = NULL;
	info->texture.floor = NULL;
	info->texture.ceiling = NULL;
}

int	all_info(t_info *info)
{
	if (!info->texture.n_wall || !info->texture.s_wall
		|| !info->texture.e_wall || !info->texture.w_wall
		|| !info->texture.floor || !info->texture.ceiling)
		return (0);
	return (1);
}

int	right_range(char *split)
{
	int	i;

	i = 0;
	if (!split || split[0] == '\n')
		return (0);
	if (!all_num(split))
		return (0);
	if (ft_atoi(split) < 0 || ft_atoi(split) > 255)
		return (0);
	return (1);
}

int	color_range(char *str, int v, t_info *info)
{
	char	**split;
	int		i;

	if (!coma_check(str))
		return (0);
	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if (!right_range(split[i]))
		{
			free_dub_tab(split, 2147483647);
			return (0);
		}
	}
	if (i != 3)
	{
		free_dub_tab(split, 2147483647);
		return (0);
	}	
	i = -1;
	color_int(split, v, info);
	free_dub_tab(split, 3);
	return (1);
}

int	check_info(t_info *info)
{
	if (!all_info(info))
		return (printf("Error :texture : missing information\n"));
	if (!color_range(info->texture.floor, 1, info))
		return (printf("Error :range color : floor\n"));
	if (!color_range(info->texture.ceiling, 2, info))
		return (printf("Error :range color : ceiling\n"));
	return (0);
}
