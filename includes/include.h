/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:54 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/17 10:42:39 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SIZE 20
# define X	80
# define Y	80
# define PX	64

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
	void	*mlx;
	void	*win;
};

/*	MAP */

int	map_maker(char **argv, t_info *info);
void	draw(t_info *info);

#endif
