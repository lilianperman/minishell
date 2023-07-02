#include "minishell.h"

int	main(void)
{
	t_token		*tkn;
	t_sentence	*sentence;
	const int	size_sent = 3;
	const int	size_tkn = 4;
	int			i;
	int			j;

	tkn = NULL;
	sentence = NULL;
	i = 0;
	while (i < size_sent)
	{
		j = 0;
		while (j < size_tkn)
		{
			addback_token(&tkn, new_token(ft_strdup("test"), WORD));
			j++;
		}
		addback_token(&tkn, new_token(ft_strdup("|"), PIPE));
		i++;
	}
	create_sentences(NULL, &tkn, &sentence);
	clear_token(&tkn);
	clear_sentence(&sentence);
	return (0);
}
