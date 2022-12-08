# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:40:50 by pyammoun          #+#    #+#              #
#    Updated: 2022/12/08 23:27:31 by pyammoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${addprefix	src/main/, main.c}
SRCS += ${addprefix src/map/, filling_map.c map.c map2.c drawing_map.c drawing_map_wall.c map_utils.c}
SRCS += ${addprefix src/raycast/, wall.c raycast_utils.c}
SRCS += ${addprefix get_next_line/, get_next_line_utils.c get_next_line.c}
SRCS += ${addprefix src/texture/, getting_texture.c texture_utils.c check_info.c get_map.c} 
SRCS += ${addprefix src/hooks/, hooks.c key_management.c}
HEADERFILES := include/include.h
BUILD_DIR 	?= ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
NAME        =	cub3D
AR    		=	ar rcs
GCC       	=	gcc 
RM       	=	rm -f
CFLAGS    	=	-Wall -Wextra -Werror -g
INC_FLAGS 	:= -Ilibft/incs
INC_DIR 	?= ./includes
INC_FLAGS 	+= $(addprefix -I,$(INC_DIRS))
LBFT_PATH	=	./libft/
MLX_PATH 	=	./mlx/
FRAMLIBS  	=   -framework OpenGL -framework AppKit
LIB    		:= $(LBFT_PATH)/libft.a 
LIB_MLX		:= $(MLX_PATH)/libmlx.a


all:	$(NAME)

%.c.o: $(HEADERFILES)	
	$(GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIB) $(LIB_MLX) $(OBJS)
		@echo Linking $@
		@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB) $(LIB_MLX) $(FRAMLIBS) -o $(NAME)

$(LIB):
		@$(MAKE) -C $(LBFT_PATH)
		@echo Libft done
$(LIB_MLX):
		@$(MAKE) -C $(MLX_PATH)
		@echo MLX done

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean

fclean:        clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

norm :
	norminette $(SRCS)

.PHONY:		all clean fclean re norm
