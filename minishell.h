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
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
# include <fcntl.h>

//retourne 1 en cas de probleme mineurs, si la commande ne peut pas acceder au subdirectory
# define ERR_FILE_DIR "No such file or directory\n"
//retourne 127 en cas de commande non trouvee
# define CMD_NOT_FOUND "command not found\n"
//probleme avec les redirections et le echo $> 258
# define SYNTX_ERROR "syntax error near unexpected token `newline'\n"
//probleme de quotes non fermees status 1
# define UNCLOSED_QUOTES "syntax error unclosed quotes\n"




//to execute est une variable qui est a 1 si il faut executer ce quil y a a l interieur et 
//display si elle est a 0

typedef struct s_token
{
	char			*arg;
	int				to_execute;
	int				enum_exec;
	void			*type;
	struct s_token	*next;
}				t_token;

typedef struct s_word
{
	char		*word;

}				t_word;

typedef struct s_expand
{
	char		**env;
	
}				t_expand;


typedef struct s_access
{

	int			last_exit_status;
}				t_access;

enum exec
{
	CMD = 1,
	ARG = 2,
	CHEVRON_1 = 3,
	CHEVRON_2 = 4,
	PIPE = 5,
	HERE_DOC = 6,
	EXPORT = 7,
	APPEND = 8
};

// enum pour le status est pour savoir dans quel endroit se trouve misihell
// enum status
// {

// };

int		print_errors(int status, char *str, t_token **token);
int		lexing_words(t_token **tokens, char *line);
char	*get_clean_line(char *line);
int		ft_get_words(char *line, t_token **token);
int		is_there_quotes(char *line);
char	**ft_split(char const *s, char c);
char	**ft_split_with_quotes(char const *s, char c);
char	*cleaning_str(char *str);
int		new_value_to_malloc(char *str);
char	*copy_str(char *str, int mall);
void	new_node(t_token **token, int status, char *arg);
t_token	*find_last_node(t_token *token);
void	clear_list(t_token **token);
int		syntax_analisis(t_token *base);

#endif
