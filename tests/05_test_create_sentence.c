/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:24 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/17 15:56:24 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_global = 0;

int	main(void)
{
	char *buffer;
	t_token *lst;
	t_sentence *lst_sen;
	int ver = 0; //verificação de retorno do teste

	buffer = NULL;
	lst = NULL;
	lst_sen = NULL;

	buffer = " Test variable $a for expansion < \"\" < Test \'$a\' no expansion | \"\"ls\"\" | \"\'teste4\'\" > clear | cat << $USER | cat << \"$USER\"";

	/* CRIAÇÃO DA LISTA DE TOKENS */
	scan_line(&lst, buffer);

	/* CRIAÇÃO DA T_ENV PARA TESTE */
	t_env	*var1;
	t_env	*var2;
	var1 = malloc(sizeof(*var1));
	var2 = malloc(sizeof(*var2));
	if (!(var1 && var2))
		return (1);
	var1->key = ft_strdup("a");
	var1->value = ft_strdup("var1");
	var2->key = ft_strdup("b");
	var2->value = NULL;
	var1->next = var2;
	var2->next = NULL;

	/* CRIAÇÃO DA LISTA DE SENTENÇAS*/
    create_sentences(var1, &lst, &lst_sen);

	/* CRIA UMA STRING A PARTIR DA LISTA DE SENTENÇAS*/
	char *check;
	check = NULL;
	int n = 0;
	while (lst_sen)
	{
		char **teste = lst_sen->args;
		int i;
		i = 0;
		while (teste[i])
		{
			check = ft_strjoin_free(check, teste[i]);
			check = ft_strjoin_free(check, " ");
			i++;
		}
		teste = NULL;
		lst_sen = lst_sen->next;
		n++;
	}

	/* COMPARA CHECK COM O RESULTADO ESPERADO*/
	char *correct = "Test variable var1 for expansion <  < Test $a no expansion ls \'teste4\' > clear cat << $USER cat << \"$USER\" ";
	ver = ft_strncmp(check, correct, (ft_strlen(correct) + 1));

	/* LIBERAÇÃO DA T_ENV */
	free(var1->key);
	free(var1->value);
	free(var2->key);
    free(var2->value);

	free(var1);
	free(var2);

	/* LIBERAÇÃO DA LISTA DE TOKENS */
	clear_token(&lst);
	free(lst);

	/* LIBERAÇÃO DA LISTA DE SETENÇAS */
	clear_sentence(&lst_sen);
	free(lst_sen);


	if (ver == 0 && n == 5)
	{
		ft_printf("%s\n", correct);
		ft_printf("%s\n", check);
		ft_printf("In this test the number of senteces must be 5 n:%d\n", n);
	}
	else
		ft_printf("Something is wrong with create_sentences function\n n= %d and ver=%d\n", n, ver);

	/* LIBERAÇÃO DE CHECK */
	free (check);
	return (ver);
}
