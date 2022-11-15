/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/14 18:37:44 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*filling_map(char *str, int len)
{
	int		i;
	char	*dest;
	int		str_len;

	dest = malloc((len + 1) * sizeof(*dest));
	str_len = ft_strlen(str);
	printf("len : %d\n", len);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		printf("i : %d\n", i);
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0' || i >= str_len)
			dest[i] = '1';
		else
			dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	//free(str);
	return (dest);
}

void	final_map(t_map *mapi)
{
	int	i;

	i = 0;
	mapi->h = 3;
	while (i < mapi->h)
	{
		if (mapi->w < ft_strlen(mapi->map[i]))
			mapi->w = ft_strlen(mapi->map[i]);
		i++;
	}
	i = 0;
	while (i < mapi->h)
	{
		mapi->map[i] = filling_map(mapi->map[i], mapi->w);
		i++;
	}
}
