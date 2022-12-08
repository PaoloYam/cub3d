/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:19:56 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/08 16:47:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

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
					return (printf("Error: map: floor\n"));
				if (mapi->map[m][i + 1] == ' ')
					return (printf("Error: map: floor\n"));
				if (mapi->map[m - 1][i] == ' ')
					return (printf("Error: map: floor\n"));
				if (mapi->map[m + 1][i] == ' ')
					return (printf("Error: map: floor\n"));
			}
			i++;
		}
	}	
	return (0);
}

int	control_map4(t_map *mapi)
{
	int	i;
	int	m;

	m = -1;
	i = 0;
	while (++m < (mapi->h))
	{
		i = 0;
		while (i < ft_strlen(mapi->map[m]) && mapi->map[m][i] != '\n'
			&& mapi->map[m][i] != '\0')
		{
			if (mapi->map[m][i] != ' ' && mapi->map[m][i] != '1' &&
				mapi->map[m][i] != '0' && mapi->map[m][i] != 'N' &&
				mapi->map[m][i] != 'E' && mapi->map[m][i] != 'S' &&
				mapi->map[m][i] != 'O' && mapi->map[m][i] != '\n')
				return (printf("Error: map: invalid character\n"));
			else
				i++;
		}
	}
	mapi->P = mapi->map[mapi->pos_y][mapi->pos_x];
	mapi->map[mapi->pos_y][mapi->pos_x] = '0';
	return (0);
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
					return (printf("Error: map: space\n"));
				if (mapi->map[m][i + 1] == ' ')
					return (printf("Error: map: space\n"));
				if (mapi->map[m - 1][i] == ' ')
					return (printf("Error: map: space\n"));
				if (mapi->map[m + 1][i] == ' ')
					return (printf("Error: map: space\n"));
			}
			i++;
		}
	}	
	return (0);
}

int	player_side(t_map *mapi)
{
	if (mapi->map[mapi->pos_y - 1][mapi->pos_x] != '1'
		&& mapi->map[mapi->pos_y - 1][mapi->pos_x] != '0')
		return (printf("Error: Map: Wall: Hole on player side\n"));
	if (mapi->map[mapi->pos_y + 1][mapi->pos_x] != '1'
		&& mapi->map[mapi->pos_y + 1][mapi->pos_x] != '0')
		return (printf("Error: Map: Wall: Hole on player side\n"));
	if (mapi->map[mapi->pos_y][mapi->pos_x - 1] != '1'
		&& mapi->map[mapi->pos_y][mapi->pos_x - 1] != '0')
		return (printf("Error: Map: Wall: Hole on player side\n"));
	if (mapi->map[mapi->pos_y][mapi->pos_x + 1] != '1'
		&& mapi->map[mapi->pos_y][mapi->pos_x + 1] != '0')
		return (printf("Error: Map: Wall: Hole on player side\n"));
	return (0);
}
