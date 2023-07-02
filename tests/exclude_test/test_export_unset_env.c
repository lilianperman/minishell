#include "testing.h"
#include "types.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN  "\x1b[96m"

void print_exp_unset_env(int argc, char *argv[], t_shell *info)
{
    int size = 0;
    if (ft_strncmp(argv[1], "environment", 10) == 0)
    {
        char *str1[] = {"export", "student='vchastin'"};
        char *str2[] = {"export", "_daniel=\"22 + 20\""};
        char *str3[] = {"export", "_alibaba=brasil+egito"};
        char *str4[] = {"export", "IZA="};
        printf("___________________________________________________________\n");
        printf(ANSI_COLOR_GREEN "📝 Está sendo adicionada a variável de ambiente student=vchastin\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "📝 Está sendo adicionada a variável de ambiente _daniel=22\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "📝 Está sendo adicionada a variável de ambiente _alibaba=brasil+egito\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "📝 Está sendo adicionada a variável de ambiente IZA=\n" ANSI_COLOR_RESET);
        printf("___________________________________________________________");
        export(2, str1, info->lst_env);
        usleep(2);
        export(2, str2, info->lst_env);
        usleep(2);
        export(2, str3, info->lst_env);
        usleep(2);
        export(2, str4, info->lst_env);
        usleep(2);
        printf("\n");
        printf(ANSI_COLOR_YELLOW "*********************************\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "       VÁRIAVEL DE AMBIENTE\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "*********************************\n" ANSI_COLOR_RESET);
        env(info->lst_env);
        printf("___________________________________________________________");
        printf(ANSI_COLOR_RED "\n🗑 Está sendo deletada a variável de ambiente student\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "🗑 Está sendo deletada a variável de ambiente _daniel\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "🗑 Está sendo deletada a variável de ambiente _alibaba=brasil+egito\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "🗑 Está sendo deletada a variável de ambiente IZA\n" ANSI_COLOR_RESET);
        printf("___________________________________________________________");
        char *s1[] = {"unset", "student"};
        char *s2[] = {"unset", "_daniel"};
        char *s3[] = {"unset", "_alibaba"};
        char *s4[] = {"unset", "IZA"};
        unset(2, s1, &info->lst_env);
        unset(2, s2, &info->lst_env);
        unset(2, s3, &info->lst_env);
        unset(2, s4, &info->lst_env);
        printf("\n");
        printf(ANSI_COLOR_YELLOW "*********************************\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "       VÁRIAVEL DE AMBIENTE\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "*********************************\n" ANSI_COLOR_RESET);
        env(info->lst_env);
        char *s[] = {"export"};//print especial
        usleep(59);
        printf("___________________________________________________________\n");
        printf(ANSI_COLOR_BRIGHT_MAGENTA "✍ Escrevendo apenas export no terminal\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BRIGHT_CYAN"___________________________________________________________\n"ANSI_COLOR_RESET);
        usleep(59);
	    export(1, s, info->lst_env);
        printf("\n");
        char *st1[] = {"export", "1dawe=vchastin"};
        char *st3[] = {"export", "@hotmail=22"};
        printf("❌ Esta variável de ambiente NÃO DEVE ser adicionada 1dawe=vchastin\n");
        printf("❌ Está variável de ambiente NÃO DEVE ser adicionada @hotmail=22\n");
        export(2, st1, info->lst_env);
        export(2, st3, info->lst_env);
        printf("\n");
        printf(ANSI_COLOR_YELLOW "*********************************\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "       VÁRIAVEL DE AMBIENTE\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "*********************************\n" ANSI_COLOR_RESET);
        env(info->lst_env);
    }
    else
    {
        size = argc - 1;
        char** str = (char**)malloc(size * sizeof(char*));
        for (int i = 1; i < argc; i++) {
            str[i - 1] = argv[i];
        }
        if (ft_strncmp(str[0], "export", 7) == 0)
        {
            export(size, str, info->lst_env);
            if (argc != 2)
                env(info->lst_env);
        }
        else if (ft_strncmp(str[0], "unset", 5) == 0){
            unset(size, str, &info->lst_env);
            env(info->lst_env);
        }
        else if (ft_strncmp(str[0], "env", 3) == 0){
            env(info->lst_env);
        }
        free(str);
        return ;
    }
}

int main(int argc, char *argv[], char *envp[]) {
    t_shell  info;
    if (argc == 1)
    {
        printf(ANSI_COLOR_BLUE"Tente ./printexpunsenv environment\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE"ou ./printexpunsenv export\nou ./printexpunsenv export key=value\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE"ou ./printexpunsenv unset key\nou ./printexpunsenv env\n"ANSI_COLOR_RESET);
        printf("\n");
        return (0);
    }
    printf(ANSI_COLOR_BLUE "Tente ./printexpunsenv environment\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE"ou ./printexpunsenv export\nou ./printexpunsenv export key=value\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE"ou ./printexpunsenv unset key\nou ./printexpunsenv env\n"ANSI_COLOR_RESET);
    printf("\n");
    init_shell(&info);
	info.lst_env = get_env(envp);
    print_exp_unset_env(argc, argv, &info);
    clear_env(&info.lst_env);
    return (0);
}
