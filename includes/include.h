/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:54 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/14 17:27:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SIZE 20

typedef struct s_map t_map;
struct s_map {
	char	**map;
	int		pos_y;
	int		pos_x;	
	int 	w;
	int		h;
};

typedef struct s_info	t_info;
struct s_info {
	t_map	*mapi;	
};

/*	MAP */

char	**map_maker(char **argv, t_info *info);
void	final_map(t_map *mapi);

#endif
