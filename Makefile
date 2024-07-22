NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iparsing -Iutils
FLAGS += -I$(HOME)/.brew/opt/readline/include #-arch arm64 #-arch arm64 pour mac puce m1
READLINE += -L$(HOME)/.brew/opt/readline/lib -lreadline
SRCS =	minishell.c parsing/lexing_words.c parsing/syntax_analisis.c utils/ft_split.c utils/ft_split_with_quotes.c \
		Errors_gestion.c utils/list_related.c \
		

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