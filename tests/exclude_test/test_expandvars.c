#include "minishell.h"

int	g_global = 0;

/*
 * Teste para a função de expansão de variáveis
 * Compilar com a libft e os arquivos:
 * tests/test_expandvars.c srcs/env/expand_sentence.c srcs/env/expandvars.c srcs/env/get_value.c srcs/env/scan_sentence.c srcs/env/which_quotes.c srcs/env/ft_strnew.c srcs/env/ft_stradd_back.c srcs/env/ft_strsize.c srcs/env/ft_strsetlast.c srcs/env/ft_lst_to_str.c srcs/env/ft_strclear.c srcs/env/ft_strdelone.c srcs/env/ft_strtotallen.c
 */
int	main(void)
{
	t_env	*var1;
	t_env	*var2;
	char	**tab;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;
	char	*str9;
	char	*str10;
	char	*str11;
	char	*str12;
	char	*str13;
	char	*str14;

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
	tab = malloc(15 * sizeof(*tab));
	str1 = ft_strdup("Test variable $a for expansion");
	str2 = ft_strdup("Test-$b-for no value");
	str3 = ft_strdup("Test variable \"$a some word\" inside quotes");
	str4 = ft_strdup("Test variable \" nested \'$a\' quotes \"");
	str5 = ft_strdup("Test \'$a\' no expansion");
	str6 = ft_strdup("Test nothing to expand");
	str7 = ft_strdup("Test $ alone");
	str8 = ft_strdup("Test \'$\' in single quotes");
	str9 = ft_strdup("Test \"$\" in double quotes");
	str10 = ft_strdup("Test two variables $a $a");
	str11 = ft_strdup("Test two nested variables \"$a $a\"");
	str12 = ft_strdup("Test -$c- non-existent");
	str13 = ft_strdup("Test to-$a-expand");
	str14 = ft_strdup("Test I will be$a_var1 gone");
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = str3;
	tab[3] = str4;
	tab[4] = str5;
	tab[5] = str6;
	tab[6] = str7;
	tab[7] = str8;
	tab[8] = str9;
	tab[9] = str10;
	tab[10] = str11;
	tab[11] = str12;
	tab[12] = str13;
	tab[13] = str14;
	tab[14] = NULL;
	expandvars(tab, var1);
	free(var1->key);
	free(var1->value);
	free(var2->key);
	free(var2->value);
	free(var1);
	free(var2);
	ft_putendl_fd(tab[0], 1);
	ft_putendl_fd(tab[1], 1);
	ft_putendl_fd(tab[2], 1);
	ft_putendl_fd(tab[3], 1);
	ft_putendl_fd(tab[4], 1);
	ft_putendl_fd(tab[5], 1);
	ft_putendl_fd(tab[6], 1);
	ft_putendl_fd(tab[7], 1);
	ft_putendl_fd(tab[8], 1);
	ft_putendl_fd(tab[9], 1);
	ft_putendl_fd(tab[10], 1);
	ft_putendl_fd(tab[11], 1);
	ft_putendl_fd(tab[12], 1);
	ft_putendl_fd(tab[13], 1);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(tab[4]);
	free(tab[5]);
	free(tab[6]);
	free(tab[7]);
	free(tab[8]);
	free(tab[9]);
	free(tab[10]);
	free(tab[11]);
	free(tab[12]);
	free(tab[13]);
	free(tab);
	return (0);
}
