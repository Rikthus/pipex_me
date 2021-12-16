SRCS =	

INCS = ./includes/pipex.h

OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -I $(INCS)
LIBFT = ./libft/libft.a
NAME = pipex

all : libft $(NAME)

libft :
		make -C ./libft

%.o : %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean :
		make clean -C ./libft
		rm -f $(OBJS)

fclean : clean
		make fclean -C ./libft
		rm -f $(NAME)

re : fclean all

.PHONY : all libft clean fclean re
