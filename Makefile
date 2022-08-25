NAME = minishell

CC = gcc

RM = rm -rf

#CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libs/libft
		mv ./libs/libft/libft.a ./libft.a
#CFLAGS
		$(CC) -lreadline $(OBJ) libft.a -o $(NAME) 
clean:
		make -C ./libs/libft fclean
		rm -rf */*.o libft.a
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY:all clean fclean re