
#include "../minishell.h"

t_token	*find_last_node(t_token *tok)
{
	while (tok->next)
		tok = tok->next;
	return (tok);
}

int	check_basic_syntax(t_token *gen, t_token *current_tok)
{
	t_token	*last_tok;

	if (current_tok->enum_exec == PIPE || current_tok->enum_exec == ARG)
		return (1);
	last_tok = find_last_node(current_tok);
	if (last_tok->enum_exec == PIPE || last_tok->enum_exec == REDIR
	 || last_tok->enum_exec == APPEND || last_tok->enum_exec == HERE_DOC)
	return (1);
}
// Erreure de base
// - ARG au debut
// - PIPE au debut

// - PIPE fin de ligne
// - REDIR fin de ligne
// - APPEND fin de ligne
// - HERE_DOC fin de ligne


int	check_cmd(t_token *base, t_token *current_tok)
{
	if (current_tok->next->enum_exec == CMD)
		return (1);
	if (current_tok->prev->enum_exec == CMD)
		return (1);
	if (current_tok->next->enum_exec == EXPORT)
		return (1);
	return (0);
}

int	check_arg(t_token *base, t_token *current_tok)
{
	if (current_tok->enum->exec == ARG)
		return (0);
	else
	return (1);

}
//ARG
//pas trouve d'autres erreurs de syntaxe a part si ARG au debut de la ligne

int	check_export(t_token *base, t_token *current_token)\
{
	if (current_tok)
}

int	syntax_analisis(t_general *gen)
{
	t_token *current_tok;

	current_tok = gen->tok;
	if (!gen->tok)
		return (1);
	check_basic_syntax(gen->tok, current_tok)
	while (current_tok)
	{
		if (current_tok->enum_exec == CMD)
			check_cmd(gen->tok, current_tok);
		if (current_tok->enum_exec == ARG )
			check_arg(gen->tok, current_tok);
		if (current_tok->enum_exec == EXPORT)
			check_export(gen->tok, current_tok);
		if (current_tok->enum_exec == HERE_DOC)
			check_here_doc(gen->tok, current_tok);
		if (current_tok->enum_exec == CHEVRON_1 ||current_tok->enum_exec == CHEVRON_2)
			check_redir(gen->tok, current_tok);
		if (current_tok->enum_exec == PIPE)
			check_pipe(gen->tok, current_tok);
		if (current_tok->enum_exec == APPEND)
			check_append(gen->tok, current_tok);
		current_tok = current_tok->next;
	}
}
// fonction qui verifie le type de token et qui appelle la fonction de verification de syntaxe correspondante
















// recevoir la structure avec la liste chainee dedans
// verifier direct les erreures de syntaxe evidentes

// faire une fonction qui verifie si chaque token est suivi et precede du bon token
// 
// 

