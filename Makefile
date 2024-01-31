# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:44:25 by bluzi             #+#    #+#              #
#    Updated: 2023/05/24 17:37:03 by bluzi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

CFLAGS		:= -Wextra -Wall -Werror
LIBMLX_F	:= lib/MLX42
LIBFT_F		:= lib/libft

LIBMLX		:= $(LIBMLX_F)/build/libmlx42.a
LIBFT		:= $(LIBFT_F)/libft.a


HEADERS		:= -I include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX) $(LIBFT) -ldl -L"../../../homebrew/Cellar/glfw/3.3.8/lib/" -lglfw -pthread -lm
SRCS		:= ${wildcard src/*.c}
BNS_SRCS	:= ${wildcard bns_src/*.c}
OBJS		:= ${SRCS:.c=.o}
BNS_OBJS	:= ${BNS_SRCS:.c=.o}

all: $(LIBMLX) $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBMLX): 
	@cmake $(LIBMLX_F) -B $(LIBMLX_F)/build && make -C $(LIBMLX_F)/build -j4

$(LIBFT):
	@make all -C $(LIBFT_F)
	@make clean -C $(LIBFT_F)


$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: $(LIBMLX) $(LIBFT) $(BNS_OBJS)
	@$(CC) $(BNS_OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(BNS_OBJS)

fclean: clean
	@rm -f $(NAME)

clean_lib:
	@make fclean -C $(LIBFT_F)
	@rm -rf $(LIBMLX_F)/build

re: fclean all

rebonus: fclean bonus

.PHONY: all, clean, fclean, re, bonus, clean_lib, rebonus