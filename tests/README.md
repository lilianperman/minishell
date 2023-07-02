 
## GUIDELINE TO UNIT TESTING

>  Unit testing in this project will run as  `tests` in the  Makefile.

>  Every unit test is a stand-alone .c file and it will be compiled using readline, lift, ft_printf, and minishell objects, just like the mini-shell itself.

>  Traces can  be found in folder `logs/`

Please check the following rules  while coding your tests:

- 1.	Test file shall be named like test_branch.c i.e. **test_parsing.c**;
- 2.	All coding for a test should run under stand-alone test_file.c only;
- 3.	This specific header should be used: `#include "unit_test.h"`;
- 4.	`main()`  will return (0) for success or any positive int for failure;
- 5.	Everything printed out will be collected in a logfile (both FD 1 and  2);
- 6.	**Infinite loops** requiring user intervention to quit must be avoided, as it will halt the Makefile and breaches the automated testing  purpose.
- 7.	Tests should print EXPECTED output vs ACTUAL output and, in case of mismatch, an error should be returned to terminal.

> Upon delivery of the project, the folder `tests/` can be deleted and no other action will be  required to adapt to production. 

------

## DIRETRIZES PARA TESTES UNITÁRIOS

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
