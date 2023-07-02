#include "testing.h"
#include "types.h"
#include "minishell.h"

int	g_global = 0;

static char	*find_filename(char *s, int redir)
{
	char 	*str;
	char 	*filename;
	int		pos;

	if (redir == IN)
		str = ft_strchr(s, '<');
	if (redir == OUT || redir == APPEND)
		str = ft_strchr(s, '>');
	pos = (str - s) + 2;
	filename = ft_substr(s, pos , ft_strlen(s) - pos);
    if (redir == APPEND)
	{
        filename = ft_strtrim(filename, " ");
	}
    return (filename);
}

int contains_redirection(const char* str, const char* redirection) {
    if (str == NULL || redirection == NULL)
        return 0;

    int str_length = ft_strlen(str);
    int redirection_length = ft_strlen(redirection);
	int i = 0;
    if (str_length >= redirection_length) {
        while( i <= str_length - redirection_length) {
            int match = 1;
            for (int j = 0; j < redirection_length; j++) {
                if (str[i + j] != redirection[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                /*verificar se o caractere seguinte é um espaço em branco
				assim evita confundir o redirecionamento '>>' com '>' */
                if (str[i + redirection_length] == ' ') {
                    return 1;
                }
            }
			i++;
        }
    }
    return 0;
}



int	main(void)
{
	char *initial_args[] = { "blabla < input.txt", "beaba > output.txt", "alibaba >> output.txt"};
	/*calcula o número de elementos no array initial_args*/
    int num_args = sizeof(initial_args) / sizeof(initial_args[0]);
	int i = 0;

    t_sentence st;
    st.args = malloc((num_args + 1) * sizeof(char *));
    if (st.args == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }
	/* percorrendo o array initial_args e fazendo a cópia de cada elemento
	para o array st.args da estrutura t_sentence, usando a função strdup.*/
    while (i < num_args)
	{
        st.args[i] = ft_strdup(initial_args[i]);
        if (st.args[i] == NULL) {
            printf("Falha na alocação de memória.\n");
            for (int j = 0; j < i; j++) {
                free(st.args[j]);
            }
            free(st.args);
            return 1;
        }
		i++;
    }
    st.args[num_args] = NULL;
	i = 0;
    while (i < num_args) {
        if (contains_redirection(st.args[i], ">>")) {
            open_reds(APPEND, &st, find_filename(st.args[i], APPEND));
            printf("Encontrou redirecionamento \">>\": %s\n", st.args[i]);
        } else if (contains_redirection(st.args[i], ">")) {
           	open_reds(OUT, &st, find_filename(st.args[i], OUT));
            printf("Encontrou redirecionamento \">\": %s\n", st.args[i]);
        } else if (contains_redirection(st.args[i], "<")) {
           	open_reds(IN, &st, find_filename(st.args[i], IN));
            printf("Encontrou redirecionamento \"<\": %s\n", st.args[i]);
		}
		i++;
    }
	i = 0;
    while (i < num_args) {
        free(st.args[i++]);
    }
    free(st.args);
	return 0;
}
