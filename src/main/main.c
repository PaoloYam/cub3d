/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/14 18:12:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_info	info;
	(void)info;
	t_map	mapi;

	mapi.map = malloc(3 * sizeof(*mapi.map));
	mapi.map[0] = malloc(ft_strlen(argv[1]) * sizeof(*mapi.map));
	mapi.map[1] = malloc(ft_strlen(argv[2])* sizeof(*mapi.map));
	mapi.map[2] = malloc(ft_strlen(argv[3])* sizeof(*mapi.map));
	mapi.map[0] = argv[1];
	mapi.map[1] = argv[2];
	mapi.map[2] = argv[3];
	printf("avant %s\n", mapi.map[0]);
	printf("avant %s\n", mapi.map[1]);
	printf("avant %s\n", mapi.map[2]);
	final_map(&mapi);
	printf("\n");
	printf("%s\n", mapi.map[0]);
	printf("%s\n", mapi.map[1]);
	printf("%s\n", mapi.map[2]);

	//map_maker(argv, &info);
	return (0);
}
