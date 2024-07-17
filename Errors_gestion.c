#include "minishell.h"

int	print_errors(int status, char *str, t_token **token)
{
    // t_token *temp;
    (void)token;

    // if (token)
    // {
    //     while ((*token)->next)
    //     {
    //         temp = (*token)->next;
    //         free ((*token)->arg);
    //         free ((*token));
    //         (*token) = temp;
    //     }
    //     free ((*token));
    // }
    printf("%s", str);
    return (status);
}
