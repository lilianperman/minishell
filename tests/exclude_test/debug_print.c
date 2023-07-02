#include "testing.h"

static void	print_token(t_token *cmd);

void	print_data(void *ptr, t_test t)
{
	if (t == TOKEN)
		print_token((t_token *)ptr);
}

static void	print_token(t_token *cmd)
{
	while (cmd)
	{
		printf("Token = %i\n", cmd->tkn);
		printf("Word = %s\n", cmd->word);
		printf("\n");
		cmd = cmd->next;
	}
	printf("\n");
}
