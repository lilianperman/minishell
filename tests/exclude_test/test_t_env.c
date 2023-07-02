#include "minishell.h"
#include "testing.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	**create_fake_env(void);
static void	fake_init(t_shell *data, char **fenv);
static void	call_unset(t_shell *data, const char *to_remove);
static void	print_list(t_env *lst, int size);

int	main(void)
{
	t_shell	data;
	char	**fake_env;

	fake_env = create_fake_env();
	fake_init(&data, fake_env);
	freetab((void **)fake_env);
	print_list(data.lst_env, 5);
	call_unset(&data, "var3");
	print_list(data.lst_env, 4);
	call_unset(&data, "var5");
	print_list(data.lst_env, 3);
	printf("Calling env:\n");
	env(data.lst_env);
	clear_env(&data.lst_env);
	return (0);
}

static void	fake_init(t_shell *data, char **fenv)
{
	data->line = NULL;
	data->lst_env = get_env(fenv);
	data->lst_token = NULL;
}

static char	**create_fake_env(void)
{
	char		**fenv;
	const int	size = 5;

	fenv = malloc((size + 1) * sizeof(*fenv));
	fenv[0] = strdup("var1=aaa");
	fenv[1] = strdup("var2=bbb");
	fenv[2] = strdup("var3=ccc");
	fenv[3] = strdup("var4=");
	fenv[4] = strdup("var5==eee=eee=");
	fenv[5] = NULL;
	return (fenv);
}

static void	call_unset(t_shell *data, const char *to_remove)
{
	char	**arg;

	arg = malloc(3 * sizeof(*arg));
	arg[2] = NULL;
	arg[1] = strdup(to_remove);
	arg[0] = strdup("unset");
	unset(2, arg, &data->lst_env);
	freetab((void **)arg);
}

static void	print_list(t_env *lst, int size)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("[%d]\n", i);
		printf("key = %s\nvalue = %s\nsize = %i\n\n", lst->key, lst->value, *lst->size);
		i++;
		lst = lst->next;
	}
	if (i == size)
		printf("-----\nOK\n-----\n\n");
	else
		printf("-----\nERROR\n-----\n\n");
}
