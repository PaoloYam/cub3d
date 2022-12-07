/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/07 18:23:55 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	line_number(char *argv, t_info *info)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i = i + 1;
	}
	info->mapi.h = i;
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
	while (map[line][++i])
		if (map[line][i] != '1' && map[line][i] != ' ')
			return (0);
	m = -1;
	while (++m <= line)
		if ((map[m][0] != '1') || (map[m][(ft_strlen(map[m]) - 2)] != '1'))
			return (0);
	m = -1;
	i = -1;
	while (++m <= line)
	{
		while (map[m][++i] == ' ' && map[m][i])
			if (i == ft_strlen(map[m]) || map[m][0] == '\n')
				return (0);
	}
	return (1);
}

void	player_position(t_map *mapi, int m, int i, int *c)
{
	while (mapi->map[m][++i])
	{
		if (mapi->map[m][i] == 'N' || mapi->map[m][i] == 'E' ||
				mapi->map[m][i] == 'S' || mapi->map[m][i] == 'W')
		{
			if (*c == 1)
				*c = 0;
			else if (*c == 0)
				*c = 1;
			mapi->pos_x = i;
			mapi->pos_y = m;
			mapi->co_x = (i * X) + ((X / 2) - (P_SIZE / 2));
			mapi->co_y = (m * Y) + (Y / 2) - (P_SIZE / 2);
		}	
	}
}

int	control_map2(t_map *mapi)
{
	int	i;
	int	m;
	int	c;

	m = -1;
	c = 0;
	while (++m < (mapi->h - 1))
	{
		i = -1;
		player_position(mapi, m, i, &c);
	}
	if (c == 0)
		return (0);
	else
		return (1);
}

int	map_maker(t_info *info)
{
	int		i;

	i = 0;
	if (!control_map(info->mapi.map, info->mapi.h - 1))
		return (0);
	if (!control_map2(&info->mapi))
		return (0);
	if (!control_map3(&info->mapi))
		return (0);
	if (!control_map4(&info->mapi))
		return (0);
	if (!control_map5(&info->mapi))
		return (0);
	final_map(&info->mapi);
	return (1);
}
