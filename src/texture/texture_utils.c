/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:50:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 12:24:54 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	free_dub_tab(char **str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (i < n && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	all_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1])
	{
		printf("Error :range color : ""00"" value is not valid\n");
		return (0);
	}
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	free_texture(t_info *info, int line)
{
	free_dub_tab(info->info, line);
	if (info->texture.n_wall)
		free(info->texture.n_wall);
	if (info->texture.s_wall)
		free(info->texture.s_wall);
	if (info->texture.e_wall)	
		free(info->texture.e_wall);
	if (info->texture.w_wall)
		free(info->texture.w_wall);	
	return (0);
}

int	integer_color(char *str)
{
	char	color[10];
	int		color_int;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			i++;
		color[j] = str[i];
		j++;
		i++;
	}
	color_int = ft_atoi(color);
	return (color_int);
}
