/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/22 17:55:27 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*filling_map(char *str, int len)
{
	int		i;
	char	*dest;
	int		str_len;

	dest = malloc((len + 1) * sizeof(char));
	str_len = ft_strlen(str);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < str_len)
		{
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
				dest[i] = '1';
			else
				dest[i] = str[i];
		}
		if (i >= str_len)
			dest[i] = '1';
		i++;
	}
	dest[i] = '\0';
	free(str);
	return (dest);
}

void	final_map(t_map *mapi)
{
	int	i;

	i = 0;
	mapi->w = 0;
	while (i < mapi->h)
	{
		if (mapi->w < ft_strlen_n(mapi->map[i]))
			mapi->w = ft_strlen_n(mapi->map[i]);
		i++;
	}
	i = 0;
	while (i < mapi->h)
	{
		mapi->map[i] = filling_map(mapi->map[i], mapi->w);
		i++;
	}
}
