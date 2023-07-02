#include "minishell.h"

typedef enum e_test
{
	UNDEFINED,
	TOKEN,
}	t_test;

// Funcção para testar scan_line().
// Compilar com os arquivos:
// tests/debug_print.c srcs/parser/isdelim.c srcs/parser/isquotes.c
// srcs/parser/scan_line.c tests/test_tokenization.c srcs/parser/which_delim.c
// srcs/data_types/t_token.c

int	main(void)
{
	char	*buffer;
	int		ret;
	t_token	*lst;
	int		ver;

	lst = NULL;
	buffer = NULL;
	ret = 0; // para armazenar retorno da lexer
	ver = 0; // verificdor de retorno da função de teste


	//opções de lines que NÂO devem retornar error, ou seja retorno de tokenization precisa ser 0
	//se desejar adicionar mais opções de teste para retorno 0, acrescente a linha deseja
	//no arquivo token_0.txt, certifique-se de não deixar uma linha em branco no final
	//e nem espeços depois de cada frase
	int fd;

	fd = open("token_0.txt", O_RDONLY);
	while (1)
	{
		buffer = ft_strtrim(get_next_line(fd), "\n");
		if (buffer)
			ft_printf("%s\n", buffer);
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		ft_printf("ret: %i\n\n", ret);
		if (lst)
			clear_token(&lst);
		if (ret == 0)
			lst = NULL;
		if (ret != 0)
		{
			ver = -1;
			break;
		}
	}
	close(fd);


	//opções de lines que DEVEM retornar error -1, ou seja retorno de tokenization precisa ser -1
	//se desejar adicionar mais opções de teste para retorno -1, acrescente a linha deseja
	//no arquivo token_-1.txt

	fd = open("token_-1.txt", O_RDONLY);

	while (1)
	{
		buffer = ft_strtrim(get_next_line(fd), "\n");
		if (buffer)
			ft_printf("%s\n", buffer);
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		ft_printf("ret: %i\n\n", ret);
		if (lst)
			clear_token(&lst);
		if (ret == -1)
			lst = NULL;
		if (ret != -1)
		{
			ver = -2;
			break;
		}
	}
	close(fd);

	//opções de lines que DEVEM retornar error -2, ou seja retorno de
	//tokenization precisa ser -2
	//se desejar adicionar mais opções de teste para retorno -2,
	//acrescente a linha deseja
	//no arquivo token_-2.txt, certifique-se de não deixar uma linha em branco 
	//no final
	//e nem espeços depois de cada frase

	fd = open("token_-2.txt", O_RDONLY);

	while (1)
	{
		buffer = ft_strtrim(get_next_line(fd), "\n");
		if (buffer)
			ft_printf("%s\n", buffer);
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		ft_printf("ret: %i\n\n", ret);
		if (lst)
			clear_token(&lst);
		if (ret == -2)
			lst = NULL;
		if (ret != -2)
		{
			ver = -3;
			break;
		}
	}
	close(fd);

	if (ver == 0)
		ft_printf ("\ntokenization is ok\n");
	else
		ft_printf ("\nsomething is wrong ver = %i", ver);
	return (ver);
}

