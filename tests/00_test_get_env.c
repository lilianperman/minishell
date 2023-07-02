#include "minishell.h"

int	main(void)
{
	int ver = 0; //verificação do retorno do teste
	t_env 	*lst_env;


	/* CRIAÇÃO DO ARRAY DE STRINGS PARA TESTE*/
	char *fake_envs[10];

	int i = 0;
	while (i < 10)
	{
		fake_envs[i] = NULL;
		i++;
	}

	fake_envs[0] = ft_strdup("USER=Vanesa");
	fake_envs[1] = ft_strdup("TERM_PROGRAM=iTerm.app");
	fake_envs[2] = ft_strdup("PATH=/Users/Vanessa/bin");
	fake_envs[3] = ft_strdup("MINISHELL=project");
	fake_envs[4] = ft_strdup("VAZIO=");
	fake_envs[5] = ft_strdup("SESSION=0t0p2");
	fake_envs[6] = ft_strdup("_=user/bin/env");


/* CRIAÇÃO DA T_ENV */
lst_env = get_env(fake_envs);

/* PERCORRE A T_ENV, DÁ JOIN EM KEY E VALUE E COMPARA COM AS FAKE_ENVS */
char *str_to_check = NULL;
i = 6; // obs está começando em 6 pq a função get_env está criando a lista inversamente organizada
while (lst_env)
{
	str_to_check = NULL;
	str_to_check = ft_strjoin_free(lst_env->key, "=");
	str_to_check = ft_strjoin_free(str_to_check, lst_env->value);
	ft_printf("%s", str_to_check);
	ver = strncmp(fake_envs[i], str_to_check, (ft_strlen(fake_envs[i]) + 1));
	if (ver != 0)
	{
		ver = i + 1;
		break;
	}
	free(str_to_check);
	i--;
	lst_env = lst_env->next;
}

/* LIBERAÇÃO DA FAKE_ENVS */
i = 0;
while (fake_envs[i])
{
	free(fake_envs[i]);
	i++;
}

/* LIBERAÇÃO DA T_ENV */
clear_env(&lst_env);

if (ver == 0)
	ft_printf ("Function get_env is working well\n");
else
	ft_printf ("Something is wrong with get_env function. Ver = %d\n", ver);

return (ver);
}
