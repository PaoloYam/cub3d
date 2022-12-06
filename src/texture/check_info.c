/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:40:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/06 13:07:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

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

int	color_range(char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		if (!right_range(split[i]))
		{
			free_dub_tab(split, 2147483647);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		free_dub_tab(split, 2147483647);
		return (0);
	}
	return (1);
}

int	check_info(t_info *info)
{
	if (!all_info(info))
	{
		printf("Error :texture : missing information\n");
		return (0);
	}
	if (!color_range(info->texture.floor))
	{
		printf("Error :range color : floor\n");
		return (0);
	}
	else
		info->texture.floor_int = integer_color(info->texture.floor);
	if (!color_range(info->texture.ceiling))
	{
		printf("Error :range color : ceiling\n");
		return (0);
	}
	info->texture.ceiling_int = integer_color(info->texture.ceiling);
	return (1);
}
