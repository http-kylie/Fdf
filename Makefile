CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
SRC_FILES = main.c		init_map.c		parse_map.c \
			error.C		free.C


INC_DIR = inc
OBJ_DIR = obj

all:
	make -s -C ./libft
	cc -Wall -Werror -Wextra main.c init_map.c parse_map.c parse_utils.c error.c free.c temp.c -I. -I./libft -Llibft -lft