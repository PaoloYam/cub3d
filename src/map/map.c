/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/17 12:16:49 by pyammoun         ###   ########.fr       */
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
	//verif si espace apres fin de ligne
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
		while (mapi->map[m][++i])
		{
			if (mapi->map[m][i] == 'N' || mapi->map[m][i] == 'E' ||
					mapi->map[m][i] == 'S' || mapi->map[m][i] == 'W')
			{
				if (c == 1)
					c = 0;
				else if (c == 0)	
					c = 1;	
				mapi->pos_x = i;
				mapi->pos_y = m;
			}	
		}
	}
	if (c == 0)
		return (0);
	else
		return (1);
}

int	control_map3(t_map *mapi)
{
	int	i;
	int	m;

	m = 0;
	while (++m < (mapi->h - 1))	
	{
		i = 1;
		while (i < (ft_strlen(mapi->map[m]) - 2))
		{
			if (mapi->map[m][i] == '0')
			{
				if (mapi->map[m][i - 1] == ' ')
					return (0);
				if (mapi->map[m][i + 1] == ' ')
					return (0);
				if (mapi->map[m - 1][i] == ' ')
					return (0);
				if (mapi->map[m + 1][i] == ' ')
					return (0);	
			}
			i++;
		}
	}	
	return (1);	
}

int	control_map4(t_map *mapi)
{
	int	i;
	int	m;

	m = -1;
	i = 0;
	while (++m < (mapi->h))
	{
		while (mapi->map[m][i] != '\n' && mapi->map[m][i] != '\0')
		{
			if (mapi->map[m][i] == ' ' || mapi->map[m][i] == '1' || 
				mapi->map[m][i] == '0' || mapi->map[m][i] == 'N' ||
				mapi->map[m][i] == 'E' || mapi->map[m][i] == 'S' ||
				mapi->map[m][i] == 'O' || mapi->map[m][i] == '\n') 
				i++;
			else
				return (0);	
		}
	}
	mapi->P = mapi->map[mapi->pos_y][mapi->pos_x];	
	mapi->map[mapi->pos_y][mapi->pos_x] = '0';
	return (1);
}

int	control_map5(t_map *mapi)
{
	int	i;
	int	m;

	m = 0;
	while (++m < (mapi->h - 1))	
	{
		i = 1;
		while (i < (ft_strlen(mapi->map[m]) - 2))
		{
			if (mapi->map[m][i] == 'N' || mapi->map[m][i] == 'O' ||
					mapi->map[m][i] == 'E' || mapi->map[m][i] == 'S')
			{
				if (mapi->map[m][i - 1] == ' ')
					return (0);
				if (mapi->map[m][i + 1] == ' ')
					return (0);
				if (mapi->map[m - 1][i] == ' ')
					return (0);
				if (mapi->map[m + 1][i] == ' ')
					return (0);	
			}
			i++;
		}
	}	
	return (1);	
}

int	map_maker(char **argv, t_info *info)
{
	int		i;
	int		fd;
	int		line;

	i = 0;
	line = line_number(argv[1], info);
	info->mapi.map = malloc(sizeof(*(info->mapi.map)) * line);
	if (info->mapi.map == NULL)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (i < line)
		info->mapi.map[i++] = get_next_line(fd);
	if (!control_map(info->mapi.map, line - 1))
		return (0);
	if (!control_map2(&info->mapi))
		return (0);
	if (!control_map3(&info->mapi))
		return (0);	
	if (!control_map4(&info->mapi))
		return (0);
	if (!control_map5(&info->mapi))
		return (0);	
	return (1);
}