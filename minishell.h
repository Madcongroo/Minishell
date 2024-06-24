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

// status = 1 si c est une commande, 2 si c est un arg, 3 si c est une redirection, 4 si c est un pipe
typedef struct s_tocken
{
	struct s_tocken *prev;
	char			*arg;
	int				status;
	struct s_tocken	*next;
}				t_tocken;



int		print_errors(char *str);

#endif
