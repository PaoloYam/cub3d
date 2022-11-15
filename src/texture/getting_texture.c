/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:17:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/15 18:33:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	which_texture(char **split, t_info *info)
{
	if (!split[0])
		return ;
	if (!info->texture->n_wall
		&& !ft_strncmp("NO", split[0], ft_strlen(split[0])))
		info->texture->n_wall = ft_strdup(split[1]);
	if (!info->texture->s_wall
		&& !ft_strncmp("SO", split[0], ft_strlen(split[0])))
	info->texture->s_wall = ft_strdup(split[1]);
	if (!info->texture->w_wall
		&& !ft_strncmp("WE", split[0], ft_strlen(split[0])))
	info->texture->w_wall = ft_strdup(split[1]);
	if (!info->texture->e_wall
		&& !ft_strncmp("EA", split[0], ft_strlen(split[0])))
	info->texture->e_wall = ft_strdup(split[1]);
	if (!info->texture->floor
		&& !ft_strncmp("F", split[0], ft_strlen(split[0])))
		info->texture->floor = ft_strdup(split[1]);
	if (!info->texture->ceiling
		&& !ft_strncmp("C", split[0], ft_strlen(split[0])))
		info->texture->ceiling = ft_strdup(split[1]);
	free_split(split);
}

void	get_texture(t_info *info, char *str)
{
	int		i;
	char	**split;

	i = 0;
	if (!str)
		return ;
	split = ft_split(str, ' ');
	which_texture(split, info);
}

int	load_info(t_info *info, char **argv)
{
	t_texture	texture;
	int			line;
	int			fd;
	int			i;

	info->texture = &texture;
	line = line_number(argv[1], info);
	info->info = malloc(line * sizeof(*(info->info)));
	if (!info->info)
		return (0);
	fd = open(argv[1], O_RDONLY);
	initialize_texture(info);
	i = -1;
	while (++i < line)
	{
		info->info[i] = get_next_line(fd);
		get_texture(info, info->info[i]);
		if (all_info(info))
		{
			load_map(i, line, fd, info);
			break ;
		}
	}
	if (!check_info(info))
		return (0);
	//free info;
	return (1);
}
