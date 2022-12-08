/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:40:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 21:41:20 by tbrulhar         ###   ########.fr       */
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

int	color_range(char *str)
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
	while (i < 3)
		free(split[++i]);
	free(split);
	return (1);
}

int	check_info(t_info *info)
{
	if (!all_info(info))
		return (printf("Error :texture : missing information\n"));
	if (!color_range(info->texture.floor))
		return (printf("Error :range color : floor\n"));
	info->texture.floor_int = integer_color(info->texture.floor);
	if (!color_range(info->texture.ceiling))
		return (printf("Error :range color : ceiling\n"));
	info->texture.ceiling_int = integer_color(info->texture.ceiling);
	return (0);
}
