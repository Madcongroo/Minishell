NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS += -I$(HOME)/.brew/opt/readline/include
READLINE += -L$(HOME)/.brew/opt/readline/lib
SRCS = minshell.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECT) $(READLINE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECT) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: clean fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re