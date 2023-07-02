#include "minishell.h"

int	main(void)
{
	const char	*str = "test test test test";
	char		**arg1 = ft_split(str, ' ');
	char		**arg2 = ft_split(str, ' ');
	char		**arg3 = ft_split(str, ' ');
	t_sentence	*s;

	s = new_sentence(arg1);
	addback_sentence(&s, new_sentence(arg2));
	addback_sentence(&s, new_sentence(arg3));
	clear_sentence(&s);
	return (0);
}
