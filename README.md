# minishell
[![Unit Testing](https://github.com/izacabral/minishell/actions/workflows/unit-tests.yml/badge.svg?branch=develop)](https://github.com/izacabral/minishell/actions/workflows/unit-tests.yml)
[![Norminette](https://github.com/izacabral/minishell/actions/workflows/norminette.yml/badge.svg?branch=develop)](https://github.com/izacabral/minishell/actions/workflows/norminette.yml)
## Checkilist para Pull Requests
- [x] Verifique a Norma e (inclua cabeçalho)
- [x] Inclua o teste unitário da sua funçao na pasta `tests/` e rode `make tests` localmente.
- [x] Rode `make fclean` na pasta principal (para que os binários não sejam incluídos!)
> Github Actions irá verificar o Pull Request antes do Merge. Em caso de falha, não submeta seu código antes de revisá-lo. Os badges de Norminette e Testes Unitários serão atualizados de acordo com o resultado dos testes.

## Diretrizes para Testes Unitários

> O teste unitário neste projeto será executado como `tests` no Makefile.

> Cada teste unitário é um arquivo .c autônomo e será compilado usando objetos readline, lift, ft_printf e minishell, assim como o próprio minishell.

> Registros de execução podem ser encontrados na pasta `logs/`

Verifique as seguintes regras ao codificar seus testes:

- 1. O arquivo de teste deve ser nomeado como test_branch.c, ou seja, **test_parsing.c**;
- 2. Toda a codificação de um teste deve ser executada apenas em test_file.c independente;
- 3. Este cabeçalho específico deve ser usado: `#include "unit_test.h"`;
- 4. `main()` retornará (0) para sucesso ou qualquer int positivo para falha;
- 5. Tudo o que for impresso será coletado em um logfile (tanto FD 1 quanto 2);
- 6. **Loops infinitos** que requerem a intervenção do usuário para sair devem ser evitados, pois isso interromperá o Makefile e violará o objetivo do teste automatizado.
- 7. Os testes devem imprimir a saída ESPERADA versus a saída REAL e, em caso de incompatibilidade, um erro deve ser retornado ao terminal.

> Após a entrega do projeto, a pasta `tests/` poderá ser deletada e nenhuma outra ação será necessária para adaptação à produção.

## instruções para manutenção do repositório

![Screen Shot 2023-04-13 at 6 41 49 PM](https://user-images.githubusercontent.com/107276428/231889316-78f4833c-3668-455c-9e65-d354a5f1a26b.png)

- Todo mundo deverá baixar a Develop e fazer uma nova branch para trabalhar
- Quando tiver sua parte pronta ou quiser apresentar, fazer um pull request para Develop
- Quando tivermos concluído uma etapa do projeto, fazer merge na develop na main, com pull request

