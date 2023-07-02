/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:24 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/06 12:29:16 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

//Função para testar o lexer
int	main(void)
{
	char	*buffer[30];
	int 	ret;
	t_token	*lst;
	int 	i;
	int 	ver;

	lst = NULL;
	ret = 0; // para armazenar retorno da lexer
	ver = 0; // verificdor de retorno da função de teste

	//setando strings para nulo
	i = 0;
	while (i < 30)
	{
		buffer[i] = NULL;
		i++;
	}

	//strings que NÃO devem retornar erros, ou seja retorno de lexer precisa ser 0
	buffer[0] = "cat teste > teste2";
	buffer[1] = "cat teste > teste2 | wc";
	buffer[2] = "cat teste | wc";
	buffer[3] = "cat teste | wc < teste2";
	buffer[4] = "cat teste2 < teste3 |ls | teste4 > clear";
	buffer[5] = "cat teste2 | < teste3";
	buffer[6] = "cat teste2 |< teste3";
	buffer[7] = "cat teste2 |";
	buffer[8] = "cat main.c |> teste";
	buffer[9] = "<< EOF";
	buffer[10] = "cat > teste main.c";
	buffer[11] = "> teste cat main.c";

	// percorrer as strings acima criando a lista de tokens e verificando se o retorno de lexer é 0
	// se lexer não for 0, retorna -1
	i = 0;
	while (buffer[i])
	{
		scan_line(&lst, buffer[i]);
		ret = lexer(lst);
		if (lst)
		{
			clear_token(&lst);
		}
		if (ret == 0)
		{
			lst = NULL;
			i++;
		}
		if (ret != 0)
		{
			ver = -1;
			break;
		}
	}

	//setando strings para nulo
	i = 0;
	while (i < 30)
	{
		buffer[i] = NULL;
		i++;
	}

	//strings que DEVEM retornar erros de syntax, ou seja retorno de lexer precisa ser -2
	buffer[0] = "| teste2";
	buffer[1] = "|teste2";
	buffer[2] = "< | teste3";
	buffer[3] = "<| teste3";
	buffer[4] = "cat teste2 <| teste3";
	buffer[5] = "cat teste2 < |";
	buffer[6] = "cat teste2 < | teste3";
	buffer[7] = "cat teste2 <";
	buffer[8] = "<< |";
	buffer[9] = "<<|";
	buffer[10] = "cat teste2 << | teste3";
	buffer[11] = "cat teste2 <<";
	buffer[12] = "cat teste2 >>| teste3";
	buffer[13] = "cat teste2 >>";
	buffer[14] = "cat teste2 > | teste3";
	buffer[15] = "cat teste2 > |";
	buffer[16] = "cat teste2 > ";
	buffer[17] = "<";
	buffer[18] = "<<";
	buffer[19] = ">>";
	buffer[20] = ">";
	buffer[21] = "cat teste || wc -l";
	buffer[22] = "cat teste ||| wc -l";
	buffer[23] = "cat teste | | wc -l";
	buffer[24] = "cat teste | || wc -l";
	buffer[25] = "cat teste || | wc -l";


	// percorrer as strings acima criando a lista de tokens e verificando se o retorno de lexer é -2
	// se lexer não for -2, retorna -2
	i = 0;
	while (buffer[i])
	{
		scan_line(&lst, buffer[i]);
		ft_printf("buffer[%i]:  %s\n", i, buffer[i]);
		ret = lexer(lst);
		ft_printf("\n");
		if (lst)
		{
			clear_token(&lst);
		}
		if (ret == -2)
		{
			lst = NULL;
			i++;
		}
		if (ret != -2)
		{
			ver = -2;
			break;
		}
	}
	if (ver == 0)
		ft_printf ("\n\nlexer is ok\n");
	else
		ft_printf ("\n\nsomething is wrong ver = %i", ver);
	return (ver);
}

