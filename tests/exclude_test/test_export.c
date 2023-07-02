#include "minishell.h"
#include "types.h"
#include <stdio.h>
#include <string.h>

static char	**create_fake_env(void);
static void	fake_init(t_shell *data, char **fenv);
static void	print_list(t_env *lst);
static void	run_tests(t_env *lst);
static void test_export(char *str, t_env *lst);
static char	**create_args(char *str);
static int	count_args(char **args);

int	main(void)
{
	t_shell	data;
	char	**fake_env;

	fake_env = create_fake_env();
	fake_init(&data, fake_env);
	freetab((void **)fake_env);
	run_tests(data.lst_env);
	printf("End of test\nList:\n");
	print_list(data.lst_env);
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
	fenv[3] = strdup("var4=ddd");
	fenv[4] = strdup("var5==eee=eee=");
	fenv[5] = NULL;
	return (fenv);
}

static void	run_tests(t_env *lst)
{
	const char	*test1 = "export var6=fff var7=ggg";
	const char	*test2 = "export var1=111 var5=";
	const char	*test3 = "export 1var=zzz var8=hhh var8=888";
	const char	*test4 = "export";

	printf("Adding variables\nCall: %s\n", test1);
	test_export((char *)test1, lst);
	print_list(lst);
	printf("\nModifying variables\nCall %s\n", test2);
	test_export((char *)test2, lst);;
	print_list(lst);
	printf("\nInvalid entry\nCall %s\n", test3);
	test_export((char *)test3, lst);
	printf("Test export for print variables\n");
	test_export((char *)test4, lst);
}

static void test_export(char *str, t_env *lst)
{
	char	**args;
	int		ctr;

	args = create_args(str);
	ctr = count_args(args);
	export(ctr, args, lst);
	freetab((void **)args);
}

static char	**create_args(char *str)
{
	return (ft_split(str, ' '));
}

static int	count_args(char **args)
{
	int	ctr;

	ctr = 0;
	while (args[ctr])
		ctr++;
	return (ctr);
}

static void	print_list(t_env *lst)
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
}
