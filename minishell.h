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
# include "libft/libft.h"

//retourne 1 en cas de probleme mineurs, si la commande ne peut pas acceder au subdirectory
# define ERR_FILE_DIR "No such file or directory\n"
//retourne 127 en cas de commande non trouvee
# define CMD_NOT_FOUND "command not found\n"
//probleme avec les redirections et le echo $> 258
# define SYNTX_ERROR "syntax error near unexpected token `newline'\n"
//probleme de quotes non fermees status 1
# define UNCLOSED_QUOTES "syntax error unclosed quotes\n"




// to execute est une variable qui est a 1 si il faut executer ce quil y a a l interieur et 
// display si elle est a 0

// la varibale to split est juste pour savoir si je dois split les args dans le cas ou une
// varibale cree a un espace a l interieur (var="echo salut") et que je dois donc creer un autre node pour pouvoir
// executer la commande (si to_split == 1 il faut que je split en deux node)

typedef struct s_token
{
	// struct s_token	*prev;
	char			*arg;
	int				to_split;
	int				enum_exec;
	int				fd_in;
	int				fd_out;
	struct s_token	*next;
}				t_token;

// type est le type de variable, variable d environnement = 0 ou expand = 1 cachee = 3
// commande cachee est un expend local qui n apparait pas dans la varibale d environnemnt
// name est une string qui contient le nom avant le (=) ex : USER, PATH, SHLVL etc.

typedef struct s_expand
{
	int				type;
	char			*name;
	char			*env;
	struct s_expand	*next;
}				t_expand;

typedef struct s_general
{
	char		*word;
	char		**env;
	t_expand	*envir;
	t_token		*tok;
}				t_general;

enum exec
{
	CMD = 1,
	ARG = 2,
	REDIR = 4,
	PIPE = 8,
	HERE_DOC = 16,
	EXPORT = 32,
	SIMPLE_QUOTE = 64,
	DOUBLE_QUOTE = 128
};

// enum pour le status est pour savoir dans quel endroit se trouve misihell
// enum status
// {

// };

int	print_errors(int status, char *str, t_general *gen);
int	new_value_to_malloc(char *str);
int	lexing_words(t_general *gen, char *line);
int	ft_get_words(char *line, t_general *gen);
int	is_there_quotes(char *line);
int	find_dollar_n_quotes(char *arg);
int	should_this_execute(char *arg);
int	check_if_quoted(char *str);
int	get_good_len(char *str, t_general *gen);
int	could_it_be_transformed(char *str, t_general *gen);




void	init_struct(t_general *gen);
void	add_env_variable(t_general *gen, char **envp);
void	new_node(t_token **token, char *arg, t_general *gen);
void	fill_token_args(t_token *new_node, char *arg, t_general *gen);
void	new_node_env(t_expand **exp, char *arg, char *name);
void	clear_list(t_token **token);
void	add_env_variable(t_general *gen, char **envp);




char	*get_clean_line(char *line);
char	**ft_split(char const *s, char c);
char	**ft_split_with_quotes(char const *s, char c);
char	*cleaning_str(char *str, t_general *gen, int doll);
char	*copy_str(char *str, int mall);
char	*each_envp_line(char *env_line, int name);
char	**get_envp_array(char **envp);
char	*could_expand(char *arg, t_general *gen, t_token *new_node);
char	*compare_env_variable(char *arg, t_general *gen);
char	*handle_quoted_dollar(char *str, t_general *gen);
char	*get_name(char *envp);




t_token		*find_last_node(t_token *token);
t_expand	*find_last_node_env(t_expand *exp);


#endif
