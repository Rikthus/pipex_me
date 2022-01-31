SRCS :=

INCS := ./includes/pipex.h

OBJS := $(SRCS:.c=.o)

CC := clang

CFLAGS := -Wall -Wextra -Werror -I $(INCS)

LIBFT := ./libft

MAKE := make

NAME := pipex

all : lib $(NAME)

lib :
		$(MAKE) -C $(LIBFT)

%.o : %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean :
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean : clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re : fclean all

.PHONY : all lib clean fclean re
