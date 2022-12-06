/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:41:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/06 13:56:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s)
		return (NULL);
	str = malloc((len + 1) * sizeof(*str));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && s[i] && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*my_strcat(char *tmp, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		len_tmp;

	i = 0;
	j = 0;
	len_tmp = 0;
	if (tmp)
		len_tmp = my_strlen(tmp);
	str = malloc((my_strlen(buffer) + len_tmp + 1) * sizeof(*str));
	if (!str)
		return (0);
	if (tmp)
	{
		while (tmp[i])
			str[j++] = tmp[i++];
	}
	i = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	free(tmp);
	return (str);
}
