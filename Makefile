NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iparsing -Iutils
FLAGS += -I$(HOME)/.brew/opt/readline/include
READLINE += -L$(HOME)/.brew/opt/readline/lib -lreadline -arch arm64
SRCS = minishell.c /parsing/tokening_line.c utils/simple_split.c \

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME) $(READLINE)

%.o: %.c
	$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re