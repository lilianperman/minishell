#include "unit_test.h"
#include <string.h>

int	g_global = 0;

static char		*find_path(char **env);
static int		test_exec1(char *path);
static char	***create_tests1(void);
static int		test_exec2(char *path);
static char	***create_tests2(void);

/*
 * Teste para a função que chama o execve
 * Compilar com a libft e os arquivos:
 * tests/test_execve.c srcs/exec/call_execve.c srcs/exec/path_to_lst.c srcs/exec/prefix_slash.c srcs/exec/launch_command.c srcs/data_types/ft_stradd_back.c srcs/data_types/ft_strclear.c srcs/data_types/ft_strdelone.c srcs/data_types/ft_strsetlast.c srcs/data_types/ft_strnew.c srcs/data_types/free_tab.c -Itests -Iinc -Ilibft -Ilibft/ft_printf -Llibft -lft
 *
 */
int	main(int argc, char **argv, char **envp)
{
	char		*p;
	int			fail;

	p = find_path(envp);
	fail = 0;
	if (test_exec1(p))
		fail = 1;
	if (test_exec2(p))
		fail = 1;
	if (fail)
		printf("\033[031mExecve FAIL\033[0m\n");
	else
		printf("\033[032mExecve OK\033[0m\n");
	(void)argc;
	(void)argv;
	return (fail);
}

static char		*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (NULL);
}

static int	test_exec1(char *path)
{
	char		***tests;
	const int	size = 4;
	int			fail;
	int			i;
	int			j;

	tests = create_tests1();
	i = 0;
	printf("\033[038;2;255;153;0mExecve should be sucessfully called\033[0m\n");
	while (i < size)
	{
		j = 0;
		printf("(%i) ", i);
		while (tests[i][j])
		{
			printf("%s ", tests[i][j]);
			j++;
		}
		printf("\n");;
		i++;
	}
	printf("\n");;
	i = 0;
	fail = 0;
	while (i < size)
	{
		if (call_execve(tests[i], path))
		{
			printf("\033[031mFailed at test: %i\033[0m\n", i);
			fail = 1;
		}
		i++;
	}
	if (!fail)
		printf("\033[032mTests with executables OK\033[0m\n\n");
	i = 0;
	while (i < size)
	{
		freetab((void **)tests[i]);
		i++;
	}
	free(tests);
	return (fail);
}

static char	***create_tests1(void)
{
	char	***tests;

	tests = malloc(4 * sizeof(*tests));
	tests[0] = malloc(2 * sizeof(**tests));
	tests[1] = malloc(2 * sizeof(**tests));
	tests[2] = malloc(2 * sizeof(**tests));
	tests[3] = malloc(3 * sizeof(**tests));
	tests[0][0] = strdup("ls");
	tests[0][1] = NULL;
	tests[1][0] = strdup("/bin/ls");
	tests[1][1] = NULL;
	tests[2][0] = strdup("./hello_world");
	tests[2][1] = NULL;
	tests[3][0] = strdup("ls");
	tests[3][1] = strdup("-l");
	tests[3][2] = NULL;
	return (tests);
}

static int	test_exec2(char *path)
{
	char	***tests;
	const int	size = 2;
	int			fail;
	int			i;
	int			j;

	tests = create_tests2();
	i = 0;
	printf("\033[038;2;255;153;0mExecve should not be called\033[0m\n");
	while (i < size)
	{
		j = 0;
		printf("(%i) ", i);
		while (tests[i][j])
		{
			printf("%s ", tests[i][j]);
			j++;
		}
		printf("\n");;
		i++;
	}
	printf("\n");;
	i = 0;
	fail = 0;
	while (i < size)
	{
		if (!call_execve(tests[i], path))
		{
			printf("\033[031mFailed at test: %i\033[0m\n", i);
			fail = 1;
		}
		i++;
	}
	if (!fail)
		printf("\033[032mTests with non executables OK\033[0m\n\n");
	i = 0;
	while (i < size)
	{
		freetab((void **)tests[i]);
		i++;
	}
	free(tests);
	return (fail);
}

static char	***create_tests2(void)
{
	char	***tests;

	tests = malloc(2 * sizeof(*tests));
	tests[0] = malloc(2 * sizeof(**tests));
	tests[1] = malloc(2 * sizeof(**tests));
	tests[0][0] = strdup("hello_world");
	tests[0][1] = NULL;
	tests[1][0] = strdup("./hello_world.txt");
	tests[1][1] = NULL;
	return (tests);
}
