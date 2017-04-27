# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csummers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 14:37:39 by csummers          #+#    #+#              #
#    Updated: 2016/11/21 14:37:40 by csummers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cubbyDB_test
CC = gcc

SRC = 			init.c \
				push.c \
				pull.c \
				remove.c \
				hash.c \
				close.c \
				main.c

# MAIN FOR TESTING

SRC_DIR = ./src/
TEST_DIR = ./test/
BUILD_DIR = ./build/

SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))
OBJ_FILES = $(addprefix $(BUILD_DIR),$(SRC:.c=.o))

HDR = -I./include
LIB = -L./libft -lft

CFLAGS = -Wall -Wextra -Werror

.PHONY: all lib clean fclean re

all: $(NAME)

build:
	mkdir $(BUILD_DIR)

lib:
	make -C libft

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | build
	$(CC) $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJ_FILES) | lib
	$(CC) $(CFLAGS) $(HDR) $(LIB) $(OBJ_FILES) -o $(NAME)

clean:
	rm -rf ./build/
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
