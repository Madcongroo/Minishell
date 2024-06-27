#ifndef minishell_H
# define minishell_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

//retourne 1 en cas de probleme mineurs, si la commande ne peut pas acceder au subdirectory
# define ERR_FILE_DIR 1 "No such file or directory\n"
//retourne 127 en cas de commande non trouvee
# define CMD_NOT_FOUND 127 "command not found\n"
//probleme avec les redirections et le echo $>
# define SYNTX_ERROR 258 "syntax error near unexpected token `newline'\n"
//probleme de quotes non fermees
# define UNCLOSED_QUOTES 1 "syntax error unclosed quotes\n"

typedef struct s_tocken
{
	char			*arg;
	int				enum_exec;
	struct s_tocken	*next;
}				t_tocken;

typedef struct s_word
{
	char		*word;

}				t_word;

enum exec
{
	CMD = 1,
	ARG = 2,
	REDIR = 3,
	PIPE = 4,
	HERE_DOC = 6,
	EXPORT = 7
};

// enum pour le status est pour savoir dans quel endroit se trouve misihell / bash
// enum status
// {


// };

int		print_errors(char *str);
int		lexing_words(t_tocken **tockens, char *line);

#endif
