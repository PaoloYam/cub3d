# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:40:50 by pyammoun          #+#    #+#              #
#    Updated: 2022/11/14 18:57:20 by pyammoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${addprefix	src/main/, main.c}
SRCS += ${addprefix src/map/, filling_map.c map.c}
SRCS += ${addprefix get_next_line/, get_next_line_utils.c get_next_line.c}
HEADERFILES := include/include.h
BUILD_DIR 	?= ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
NAME        =	cub3D
AR    		=	ar rcs
GCC       	=	gcc 
RM       	=	rm -f
CFLAGS    	=	-Wall -Wextra -Werror -g -fsanitize=address
INC_FLAGS 	:= -Ilibft/incs
INC_DIR 	?= ./includes
INC_FLAGS 	+= $(addprefix -I,$(INC_DIRS))
LBFT_PATH	=	./libft/
FRAMLIBS  	=    -L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit
READLIB 	:=	-I $(HOME)/.brew/opt/readline/include
LIB    		:= libft/libft.a 


all:	$(NAME)

%.c.o: $(HEADERFILES)	
	$(GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIB) $(OBJS)
		@echo Linking $@
		@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
		@$(MAKE) -C libft
		@echo Libft done

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean

fclean:        clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
