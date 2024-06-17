CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
INCS = -I./includes/ -I./libft/


SRCDIR = srcs/
SRCS_FIL = \
			error.c \
			free.c \
			init_map.c \
			main.c \
			parse_map.c \
			parse_utils.c \
			temp.c \
			# midpoint.c \
			# moves_counter.c \
			# operations.c \
			# sort_reorder.c \
			# target_finder.c  \
			# validator.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))


# library
LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = $(FDF)
FDF = FDF

all:  $(OBJDIR) $(FDF)

bonus: $(OBJDIR)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(FDF): $(OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(FDF) -L$(LIBFTDIR) -lft

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(FDF)
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
