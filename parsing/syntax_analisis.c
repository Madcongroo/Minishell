
#include "../minishell.h"

int	check_cmd(t_token *base, t_token *current_tok)
{
	if (current_tok->next->type == CMD)
		return (1);
	if (current_tok->prev->type == CMD)
		return (1);
	if (current_tok->next->type == EXPORT)
		return (1);
	return (0);
}

int	syntax_analisis(t_token *base)
{
	t_token *current_tok;

	current_tok = base;
	if (!base)
		return (1);
	if (current_tok->type == PIPE || current_tok->type == ARG)
		return (1);
	while (current_tok)
	{
		if (current_tok->type == CMD)
		{
			if (check_cmd(base, current_tok))
				return (1);
		}
		if (current_tok->type == ARG )
		{
			if (check_arg(base, current_tok))
				return (1);
		}
		if (current)
			
	}
}
// recevoir la structure avec la liste chainee
// faire une fonction qui verifie si chaque token est suivi du bon token

// la commande doit etre suivie d'arguments, redir, pipe operateurs, heredoc, 

