/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:54 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/14 14:01:17 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

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

#endif
