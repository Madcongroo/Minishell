NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = minshell.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECT) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: clean fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re