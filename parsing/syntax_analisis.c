
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

int	syntax_analisis(t_general *gen)
{
	t_token *current_tok;

	current_tok = gen->tok;
	if (!gen->tok)
		return (1);
	if (current_tok->enum_exec == PIPE || current_tok->enum_exec == ARG)
		return (1);
	while (current_tok)
	{
		if (current_tok->enum_exec == CMD)
		{
			if (check_cmd(gen->tok, current_tok))
				return (1);
		}
		if (current_tok->enum_exec == ARG )
		{
			if (check_arg(gen->tok, current_tok))
				return (1);
		}
		if (current_tok)
			
	}
}
// recevoir la structure avec la liste chainee
// faire une fonction qui verifie si chaque token est suivi du bon token

// la commande doit etre suivie d'arguments, redir, pipe operateurs, heredoc, 

