/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:19:56 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/07 18:24:03 by pyammoun         ###   ########.fr       */
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
		while (i < ft_strlen(mapi->map[m]) && mapi->map[m][i] != '\n'
			&& mapi->map[m][i] != '\0')
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
