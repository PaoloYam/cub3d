/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:17:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/06 20:10:39 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	which_texture(char **split, t_info *info)
{
	if (!split[0])
		return ;
	if (!info->texture.n_wall
		&& !ft_strncmp("NO", split[0], ft_strlen(split[0])))
		info->texture.n_wall = ft_strtrim(ft_strdup(split[1]), "\n");
	if (!info->texture.s_wall
		&& !ft_strncmp("SO", split[0], ft_strlen(split[0])))
	info->texture.s_wall = ft_strtrim(ft_strdup(split[1]), "\n");
	if (!info->texture.w_wall
		&& !ft_strncmp("WE", split[0], ft_strlen(split[0])))
	info->texture.w_wall = ft_strtrim(ft_strdup(split[1]), "\n");
	if (!info->texture.e_wall
		&& !ft_strncmp("EA", split[0], ft_strlen(split[0])))
	info->texture.e_wall = ft_strtrim(ft_strdup(split[1]), "\n");
	if (!info->texture.floor
		&& !ft_strncmp("F", split[0], ft_strlen(split[0])))
		info->texture.floor = ft_strtrim(ft_strdup(split[1]), "\n");
	if (!info->texture.ceiling
		&& !ft_strncmp("C", split[0], ft_strlen(split[0])))
		info->texture.ceiling = ft_strtrim(ft_strdup(split[1]), "\n");
	free_dub_tab(split, 2147483647);
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
	int			line;
	int			fd;
	int			i;

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
		return (free_texture(info, line));
	free_dub_tab(info->info, line);
	return (1);
}

void	get_wall_address(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		info->wall[i].addr = (int *)mlx_get_data_addr(info->wall[i].wall,
				&info->wall[0].bits, &info->wall[i].len, &info->wall->endian);
	}
}

int	load_texture(t_info *info)
{
	printf("path nord: %s\n", info->texture.n_wall);
	info->wall[0].wall = mlx_xpm_file_to_image(info->mlx,
			info->texture.n_wall, &info->wall[0].heigth, &info->wall[0].width);
	printf("nfo->wall[0].heigth = %d\n", info->wall[0].heigth);
	if (!info->wall[0].wall)
		return (printf("Error: texture: cannot load: Nord texture\n"));
	info->wall[1].wall = mlx_xpm_file_to_image(info->mlx,
			info->texture.s_wall, &info->wall[1].heigth, &info->wall[1].width);
	if (!info->wall[1].wall)
		return (printf("Error: texture: cannot load: Sud texture\n"));
	info->wall[2].wall = mlx_xpm_file_to_image(info->mlx,
			info->texture.e_wall, &info->wall[2].heigth, &info->wall[2].width);
	if (!info->wall[2].wall)
		return (printf("Error: texture: cannot load: Est texture\n"));
		info->wall[3].wall = mlx_xpm_file_to_image(info->mlx,
			info->texture.w_wall, &info->wall[3].heigth, &info->wall[3].width);
	if (!info->wall[3].wall)
		return (printf("Error: texture: cannot load: West texture\n"));
	get_wall_address(info);
	return (0);
}
