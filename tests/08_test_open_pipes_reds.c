/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_open_pipes_reds.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:06:41 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/14 07:06:44 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

void	print_sentence_teste(t_sentence **lst_sentence)
{
	t_sentence	*tmp;
	char		**args;
	int			i;

	tmp = *lst_sentence;
	if (!tmp)
		return ;
	while (tmp)
	{
		args = tmp->args;
		i = 0;
		while (args[i])
		{
			ft_printf("print sentence args[%d]: %s\n", i, args[i]);
			i++;
		}
		args = NULL;
		ft_printf("sentence fd_i: %d\n", tmp->fd_i);
		ft_printf("sentence fd_o: %d\n", tmp->fd_o);
		tmp = tmp->next;
	}
}

int main(void)
{
	t_shell	data;
	int		ver = 0;

	/* CRIAÇÃO DO ARRAY DE FAKE ENVS PARA TESTE */
	char **fake_envs;
	int size;
	size = 8;
	fake_envs = malloc (sizeof(char *) * size + 1);
	if (!fake_envs)
	{
		ft_printf("falha alocação das fake envs");
		ver = -1;
	}
	fake_envs[0] = ft_strdup("USER=Vanesa");
	fake_envs[1] = ft_strdup("TERM_PROGRAM=iTerm.app");
	fake_envs[2] = ft_strdup("PATH=/Users/Vanessa/bin");
	fake_envs[3] = ft_strdup("MINISHELL=project");
	fake_envs[4] = ft_strdup("VAZIO=");
	fake_envs[5] = ft_strdup("SESSION=0t0p2");
	fake_envs[6] = ft_strdup("_=user/bin/env");
	fake_envs[7] = NULL;


	init_shell(&data);
	data.lst_env = get_env(fake_envs);

	data.line = ft_strdup("echo \"hey hey\" > input.txt | Test > $MINISHELL for expansion < \"\'$MINISHELL\'\" no created | echo < project | teste >> aqui teste > aqui teste > aqui teste > aqui ls");

	/* CRIAÇÃO DA LISTA DE TOKENS */
	if (scan_line(&data.lst_token, data.line) != 0)
	{
		ver = -1;
		ft_printf("Scan_line error. Ver = %d\n", ver);
	}

	/* CHECKAGEM DO LEXER */
	if (lexer(data.lst_token) != 0)
	{
		ver = -2;
		ft_printf("Lexer error. Ver = %d\n", ver);
	}

	/* CRIAÇÃO DA LISTA DE SENTENÇAS */
	create_sentences(data.lst_env, &data.lst_token, &data.lst_sentence);

	/* CRIA UMA STRING A PARTIR DA LISTA DE SENTENÇAS*/
	char *check;
	check = NULL;
	t_sentence *lst_sen;
	lst_sen = data.lst_sentence;
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
	}

	/* COMPARA CHECK COM O RESULTADO ESPERADO*/
	char *correct = "echo hey hey > input.txt Test > project for expansion < \'project\' no created echo < project teste >> aqui teste > aqui teste > aqui teste > aqui ls ";
	if (ft_strncmp(check, correct, (ft_strlen(correct) + 1)) != 0)
	{
		ver = -3;
		ft_printf("Something wrong with create_sentences. Ver = %d\n", ver);
		ft_printf("%s\n", correct);
		ft_printf("%s\n", check);
	}
	free(check);

	/* PREENCHIMENTO E CALCULO DA QUANTIDADE DE REDS E PIPES E SEUS MALLOCS CASO EXISTAM */
	fill_shell (&data);
	if (data.sentence_count != 4)
	{
		ver = -4;
		ft_printf ("sentence_count must be 4 -> it is: %d\n", data.sentence_count);
	}

	if (data.pipe_count != 3)
	{
		ver = -5;
		ft_printf ("pipe_count must be 3 -> it is: %d\n", data.pipe_count);
	}

	if (data.redirect_count != 8)
	{
		ver = -6;
		ft_printf ("pipe_count must be 8 -> it is: %d\n", data.redirect_count);
	}

	/* ABERTURA DOS FDS COM PIPES E REDIRECTS */
	if (open_pipe_reds(&data) != 0)
	{
		ver = -7;
		ft_printf ("Something wrong with open_pipe_reds(). Ver = %d\n", ver);
	}

	/* CHECK DOS FDS CRIADOS REDIRECTS */
	if (data.reds)
	{
		if (data.reds[0] != 3)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 0, data.reds[0]);
		}
		if (data.reds[1] != 4)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 1, data.reds[1]);
		}
		if (data.reds[2] != -1)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 2, data.reds[2]);
		}
		if (data.reds[3] != 5)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 3, data.reds[3]);
		}
		if (data.reds[4] != 6)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 4, data.reds[4]);
		}
		if (data.reds[5] != 7)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 5, data.reds[5]);
		}
		if (data.reds[6] != 8)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 6, data.reds[6]);
		}
		if (data.reds[7] != 9)
		{
			ver = -7;
			ft_printf ("Something wrong with reds fd. data.reds[%d]: %d\n", 7, data.reds[7]);
		}
	}
	/* CHECK DOS FDS CRIADOS PIPES */
	if (data.pipes)
	{
		if(data.pipes[0])
		{
			if (data.pipes[0][0] != 10 && data.pipes[0][1] != 11)
			{
				ver = -8;
				ft_printf("Something wrong with pipes fd. data.pipes[0][0]: %d\n", data.pipes[0][0]);
				ft_printf("Something wrong with pipes fd. data.pipes[0][1]: %d\n", data.pipes[0][1]);
			}
		}
		if(data.pipes[1])
		{
			if (data.pipes[1][0] != 12 && data.pipes[1][1] != 13)
			{
				ver = -8;
				ft_printf("Something wrong with pipes fd. data.pipes[1][0]: %d\n", data.pipes[1][0]);
				ft_printf("Something wrong with pipes fd. data.pipes[1][1]: %d\n", data.pipes[1][1]);
			}
		}
		if(data.pipes[2])
		{
			if (data.pipes[2][0] != 14 && data.pipes[2][1] != 15)
			{
				ver = -8;
				ft_printf("Something wrong with pipes fd. data.pipes[2][0]: %d\n", data.pipes[2][0]);
				ft_printf("Something wrong with pipes fd. data.pipes[2][1]: %d\n", data.pipes[2][1]);
			}
		}
	}

	/* CLOSE NOS FDS CRIADOS */
	close_fds(&data);

	/* VERIFICANDO O ACESSO E EXISTENCIA DOS ARQUIVOS CRIADOS */
	int file = 0;
	file  = access ("input.txt", F_OK | R_OK | W_OK);
	if (file != 0)
	{
		ver = -9;
		ft_printf("Acces to the file created is not ok. Ver = %d", ver);
	}

	file  = access ("project", F_OK | R_OK | W_OK);
	if (file != 0)
	{
		ver = -10;
		ft_printf("Acces to the file created is not ok. Ver = %d", ver);
	}

	file  = access ("\'project\'", F_OK);
	if (file != -1)
	{
		ver = -11;
		ft_printf("This file should not exist. Ver = %d", ver);
	}

	file  = access ("aqui", F_OK | R_OK | W_OK);
	if (file != 0)
	{
		ver = -10;
		ft_printf("Acces to the file created is not ok. Ver = %d", ver);
	}

	/* REMOÇÃO DOS REDIRECTS E FILE NAMES DA LISTA DE SENTENÇAS*/
	clean_reds_sentences(data.lst_sentence);

	/* CRIA UMA STRING DE CHECK DA CLEAN_REDS_SENTENCES */
	char *cleaned;
	cleaned = NULL;
	lst_sen = data.lst_sentence;
	while (lst_sen)
	{
		char **teste = lst_sen->args;
		int i;
		i = 0;
		while (teste[i])
		{
			cleaned = ft_strjoin_free(cleaned, teste[i]);
			cleaned = ft_strjoin_free(cleaned, " ");
			i++;
		}
		teste = NULL;
		lst_sen = lst_sen->next;
	}

	/* COMPARA CLEANED COM O RESULTADO ESPERADO */
	char *correct2 = "echo hey hey Test for expansion no created echo teste teste teste teste ls ";
	if (ft_strncmp(cleaned, correct2, (ft_strlen(correct2) + 1)) != 0)
	{
		ver = -11;
		ft_printf("Something wrong with clean_reds_sentences. Ver = %d\n", ver);
		ft_printf("%s\n", correct2);
		ft_printf("%s\n", cleaned);
	}
	free(cleaned);

	/* VERIFICA OS FDS FINAIS DAS SENTEÇAS */
	lst_sen = data.lst_sentence;
	int n_sen = 0;
	while (lst_sen)
	{
		if (n_sen == 0)
		{
			if (lst_sen->fd_i != 0 && lst_sen->fd_o != 3)
			{
				ver = -11;
				ft_printf("lst_sen->fd_i must be 0, but it is: %d\n", lst_sen->fd_i);
				ft_printf("lst_sen->fd_o must be 3, but it is: %d\n", lst_sen->fd_o);
			}
		}
		if (n_sen == 1)
		{
			if (lst_sen->fd_i != 12 && lst_sen->fd_o != 4)
			{
				ver = -12;
				ft_printf("lst_sen->fd_i must be 12, but it is: %d\n", lst_sen->fd_i);
				ft_printf("lst_sen->fd_o must be 4, but it is: %d\n", lst_sen->fd_o);
			}
		}
		if (n_sen == 2)
		{
			if (lst_sen->fd_i != 5 && lst_sen->fd_o != 15)
			{
				ver = -13;
				ft_printf("lst_sen->fd_i must be 5, but it is: %d\n", lst_sen->fd_i);
				ft_printf("lst_sen->fd_o must be 15, but it is: %d\n", lst_sen->fd_o);
			}
		}
		if (n_sen == 3)
		{
			if (lst_sen->fd_i != 0 && lst_sen->fd_o != 9)
			{
				ver = -13;
				ft_printf("lst_sen->fd_i must be 5, but it is: %d\n", lst_sen->fd_i);
				ft_printf("lst_sen->fd_o must be 15, but it is: %d\n", lst_sen->fd_o);
			}
		}

		n_sen++;
		lst_sen = lst_sen->next;
	}

	/* PRINTA A SENTENÇA QUE VAI PRA EXECUÇÃO */
	print_sentence_teste(&data.lst_sentence);

	/* LIBERAÇÃO DAS t_ENV E FAKE ENVS */
	free_array(fake_envs);
	clear_env(&data.lst_env);

	/* LIBERAÇÃO DA T_SHELL */
	free_shell(&data);

	if (ver != 0)
	{
		ft_printf("somethin wrong whit this test. Ver = %d\n", ver);
	}
	else
		ft_printf("Open_pipes_reds is OK\n");
	return (ver);
}

