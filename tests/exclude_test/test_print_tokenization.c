#include "testing.h"


// Funcção para testar scan_line() - printando resultado.
// Compilar com os arquivos:
// tests/debug_print.c srcs/parser/isdelim.c srcs/parser/isquotes.c srcs/parser/scan_line.c tests/test_tokenization.c srcs/parser/which_delim.c srcs/data_types/t_token.c


int	main(void)
{
	char	*buffer;
	int		ret;
	t_token	*lst;

	buffer = NULL;
	lst = NULL;

	while (1)
	{
		buffer = readline("Press <Ctrl+D> to exit~ ");
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		printf("Scanner return= %i\n", ret);
		print_data((void *)lst, TOKEN);
		clear_token(&lst);
	}
	return (0);
}
