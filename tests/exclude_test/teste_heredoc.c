/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/03 15:59:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

int    main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
    t_sentence *cmd;
	t_env *lst_env;
	char *file;

	cmd = malloc (sizeof(t_sentence));
	cmd->args = NULL;
	cmd->fd_i = 0;
	cmd->fd_o = 1;
	cmd->reds_inside = 0;
	cmd->previous = NULL;
	cmd->next = NULL;

	char *arg[2];
	arg[0] = "cat";
	arg[1] = NULL;

	cmd->args = arg;
	lst_env = get_env(envp);
	file = ft_strdup("\"$USER\""); //não expande
	//file = ft_strdup("$USER"); //expande


	if ((heredoc(cmd, file, lst_env)) == -1)
	{
		ft_printf("error hdoc\n");
		return (-1);
	}


	// DESCOMENTAR ATÉ ANTES DO FORK() PARA VERIFICAR OS REDIRECIONAMENTO PARA OUTROS ARQUIVOS FUNCIONADO

	/*
	if ((cmd->fd_o = open("teste_heredoc.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	{
		ft_printf("error open\n");
		return (-2);
	}

	if ((cmd->fd_o = open("teste_heredoc.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	{
		ft_printf("error open\n");
		return (-2);
	}

	if ((cmd->fd_o = open("teste_heredoc2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	{
		ft_printf("error open\n");
		return (-2);
	}
 	*/

	int pid = fork();
	if (pid == -1)
	{
		ft_printf("error fork\n");
		return (-3);
	}
	if(pid == 0)
	{
		if (cmd->fd_i != 0)
			dup2(cmd->fd_i, 0);
		if (cmd->fd_o != 1)
			dup2(cmd->fd_o, 1);
		close (cmd->fd_i);
		int err = execve("/bin/cat", &cmd->args[0]);
		if (err == -1)
		{
			ft_printf("Could not find to execute!\n");
			return 2;
		}
	}

	wait(&pid);
	close (cmd->fd_i);
	close (cmd->fd_o);

 /*    int wstatus;
	wait(&wstatus);

     if (WIFEXITED(wstatus))
    {
        int statusCode = WEXITSTATUS(wstatus);
        if (statusCode == 0)
	        printf("Sucess!\n");
        else
	        printf("Failure with statusCode %d\n", statusCode);
    } */
	free(cmd);
	free(file);
	clear_env(&lst_env);
	return (0);
}
