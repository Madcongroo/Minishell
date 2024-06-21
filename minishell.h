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
//
# define ERROR_


typedef struct s_tocken
{
    t_args      *arg;
    t_cmd       *cmd;
    t_sep       *sep;
}               t_tocken;

typedef struct s_args
{

}               t_args;

typedef struct s_cmd
{

}               t_cmd;

typedef struct s_sep
{

}               t_sep;



int		print_errors(char *str);

#endif
