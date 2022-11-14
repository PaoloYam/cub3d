/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/14 14:30:03 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	get_position(char **map, t_vars *game)
{
	int	m;
	int	i;

	m = 0;
	while (m < game->map_h)
	{
		i = 0;
		while (i < game->map_w)
		{
			if (map[m][i] == 'P')
			{
				map->pos_y = m;
				map->pos_x = i;
			}
			i++;
		}
		m++;
	}
}

int	line_number(char *argv, t_info *info)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == 0 || fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i = i + 1;
	}
	info->mapi->h = i;
	return (i);
}

int	control_map(char **map, int line)
{
	int	i;
	int	m;

	i = -1;
	while (map[0][++i] != '\n')
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (0);
	i = -1;
	while (map[line][++i] != '\n')
		if (map[line][i++] != '1' && map[line][i++] != ' ')
			return (0);
	m = -1;
	i = -1;
	while (++m < line)
	{
		while (map[m][++i] == ' ')
		if ((map[m][i] != '1') || (map[m][(ft_strlen(map[m]) - 1)] != '1'))
			return (0);
	}	
	return (1);
}

int	control_map2(char **map, int line)
{
	int	i;
	int	m;

	m = -1;
	i = 0;
	while ()	
	
	return (1);
}

char	**map_maker(char **argv, t_info *info)
{
	int		i;
	int		fd;
	int		line;
	t_map	mapi;

	info->mapi = mapi;
	i = 0;
	line = line_number(argv[1], info);
	map = malloc(sizeof(*map) * line);
	if (map == NULL)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (i < line)
		info->mapi->map[i++] = get_next_line(fd);
	if ((control_map(info->mapi->map, line)) == 0)
		return (0);
	if ((control_map2(info->mapi->map, line)) == 0)
		return (0);
	get_position(map, game);
	return (map);
}