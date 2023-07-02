INC			=	-I ../../libft/ -I ../../libft/ft_printf/ -I ../../inc/ -I ../

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g
#-fsanitize=address

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	../../$(LFT)/$(LFT).a

# **************************************************************************** #
#    ESPECIFICAR OS ARQUIVOS PARA UM DETERMINADO TESTE                         #
# **************************************************************************** #

SRCS_P_TOKEN	=	debug_print.c test_print_tokenization.c ../../srcs/parser/isdelim.c \
					../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c ../../srcs/data_types/t_token.c

OBJS_P_TOKEN	=	$(SRCS_P_TOKEN:.c=.o)

SRCS_PWD		=	test_pwd.c ../../srcs/builtins/pwd.c

OBJS_PWD		=	$(SRCS_PWD:.c=.o)

SRCS_ECHO		=	test_echo.c ../../srcs/builtins/echo.c

OBJS_ECHO		=	$(SRCS_ECHO:.c=.o)

SRCS_EXECVE		=	test_execve.c ../../srcs/exec/call_execve.c ../../srcs/exec/path_to_lst.c ../../srcs/exec/prefix_slash.c ../../srcs/exec/launch_command.c \
					../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strsetlast.c \
					../../srcs/data_types/ft_strnew.c ../../srcs/data_types/free_tab.c \
					../../srcs/exec/default_signals.c \
					../../srcs/prompt/setup_signals.c ../../srcs/prompt/int_handler.c

OBJS_EXECVE		=	$(SRCS_EXECVE:.c=.o)

SRCS_P_EXP_UNSET_ENV	= test_export_unset_env.c ../../srcs/builtins/export_error.c ../../srcs/builtins/check_export.c ../../srcs/builtins/check_unset.c ../../srcs/builtins/env.c \
							../../srcs/builtins/compare_key.c ../../srcs/builtins/export.c \
							../../srcs/builtins/print_export.c ../../srcs/builtins/unset.c ../../srcs/data_types/free_tab.c ../../srcs/env/get_env.c \
							../../srcs/data_types/t_env.c ../../srcs/prompt/init_shell.c \
							../../srcs/data_types/protect_malloc.c \
							../../srcs/data_types/env_unlink.c \
							../../srcs/env/get_entry.c \
							../../srcs/env/check_varname.c

OBJS_P_EXP_UNSET_ENV	=	$(SRCS_P_EXP_UNSET_ENV:.c=.o)

SRCS_T_ENV	= test_t_env.c ../../srcs/builtins/export_error.c ../../srcs/builtins/check_export.c ../../srcs/builtins/check_unset.c ../../srcs/builtins/env.c \
							../../srcs/builtins/compare_key.c ../../srcs/builtins/export.c \
							../../srcs/builtins/print_export.c ../../srcs/builtins/unset.c ../../srcs/data_types/free_tab.c ../../srcs/env/get_env.c \
							../../srcs/data_types/t_env.c ../../srcs/prompt/init_shell.c \
							../../srcs/data_types/protect_malloc.c \
							../../srcs/data_types/env_unlink.c \
							../../srcs/env/get_entry.c \
							../../srcs/env/check_varname.c

OBJS_T_ENV	=	$(SRCS_T_ENV:.c=.o)

SRCS_EXPORT	= test_export.c ../../srcs/builtins/export_error.c ../../srcs/builtins/check_export.c \
							../../srcs/builtins/compare_key.c ../../srcs/builtins/export.c \
							../../srcs/builtins/print_export.c ../../srcs/data_types/free_tab.c ../../srcs/env/get_env.c \
							../../srcs/data_types/t_env.c  \
							../../srcs/data_types/protect_malloc.c \
							../../srcs/data_types/env_unlink.c \
							../../srcs/env/get_entry.c \
							../../srcs/env/check_varname.c

OBJS_EXPORT	=	$(SRCS_EXPORT:.c=.o)

SRCS_EXPANDVAR	=	test_expandvars.c ../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c ../../srcs/env/get_value.c \
						../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c ../../srcs/data_types/ft_strnew.c \
						../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c ../../srcs/data_types/ft_strsetlast.c \
						../../srcs/data_types/ft_lst_to_str.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c \
						../../srcs/data_types/ft_strtotallen.c ../../srcs/env/check_varname.c ../../srcs/parser/which_delim.c \
						../../srcs/parser/isdelim.c \
						../../srcs/env/get_global.c ../../srcs/env/swap_ptr.c \
						../../srcs/exec/args_size.c

OBJS_EXPANDVAR	=	$(SRCS_EXPANDVAR:.c=.o)

SRCS_P_SENTENCE	=	test_print_t_sentence.c  ../../srcs/sentence/create_sentences.c ../../srcs/sentence/remove_quotes.c ../../srcs/sentence/tkn_to_sentence.c \
					../../srcs/data_types/t_sentence.c ../../srcs/sentence/new_index.c ../../srcs/sentence/no_quote_size.c ../../srcs/sentence/quotes_removed.c \
					../../srcs/sentence/while_no_quotes.c ../../srcs/sentence/quote_size.c \
					../../srcs/parser/isdelim.c \
					../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c \
					../../srcs/data_types/t_token.c ../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c \
					../../srcs/env/get_value.c ../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c \
					../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c \
					../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_lst_to_str.c \
					../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strtotallen.c \
					../../srcs/env/check_varname.c ../../srcs/env/get_global.c ../../srcs/env/swap_ptr.c \
					../../srcs/exec/args_size.c \
					../../srcs/data_types/free_tab.c

OBJS_P_SENTENCE	=	$(SRCS_P_SENTENCE:.c=.o)

SRCS_SENT		=	test_sentence.c ../../srcs/data_types/t_sentence.c ../../srcs/data_types/free_tab.c

OBJS_SENT		=	$(SRCS_SENT:.c=.o)

SRCS_TKN_SENT	=	test_token_to_sentence.c ../../srcs/data_types/t_sentence.c ../../srcs/data_types/t_token.c ../../srcs/data_types/free_tab.c ../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strsize.c ../../srcs/data_types/ft_strtotallen.c ../../srcs/data_types/ft_lst_to_str.c ../../srcs/data_types/ft_strsetlast.c \
					../../srcs/sentence/create_sentences.c ../../srcs/sentence/tkn_to_sentence.c ../../srcs/sentence/remove_quotes.c ../../srcs/sentence/while_no_quotes.c ../../srcs/sentence/no_quote_size.c ../../srcs/sentence/new_index.c ../../srcs/sentence/quote_size.c ../../srcs/sentence/quotes_removed.c \
					../../srcs/env/expandvars.c ../../srcs/env/expand_sentence.c ../../srcs/env/scan_sentence.c ../../srcs/env/get_value.c ../../srcs/env/which_quotes.c ../../srcs/env/check_varname.c \
					../../srcs/parser/which_delim.c ../../srcs/parser/isdelim.c

OBJS_TKN_SENT	= $(SRCS_TKN_SENT:.c=.o)

SRCS_HDOC		= 	teste_heredoc.c \
					../../srcs/redirects/heredoc.c ../../srcs/redirects/open_reds.c \
					../../srcs/env/get_env.c ../../srcs/env/get_value.c ../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c \
					../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c \
					../../srcs/env/get_entry.c ../../srcs/env/check_varname.c \
					../../srcs/data_types/t_env.c ../../srcs/data_types/protect_malloc.c \
					../../srcs/data_types/t_token.c \
					../../srcs/sentence/while_no_quotes.c ../../srcs/sentence/quote_size.c ../../srcs/sentence/new_index.c \
					../../srcs/sentence/no_quote_size.c ../../srcs/sentence/quotes_removed.c ../../srcs/sentence/remove_quotes.c \
					../../srcs/parser/isdelim.c \
					../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c \
					../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c \
					../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_lst_to_str.c \
					../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strtotallen.c \
					../../srcs/env/get_global.c ../../srcs/env/swap_ptr.c \
					../../srcs/exec/args_size.c

OBJS_HDOC		=	$(SRCS_HDOC:.c=.o)

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

RL			=	readline
RLFLAG		= 	-lreadline

detected_OS	=	$(shell uname -s)
RL_TEST		=	if [ -z $(RL_INC) ]; then $(RL_MSG) && false; else true ; fi
NL			=	2>/dev/null

INC_RL_MAC  =	-I $(RL_INC)
LIB_RL_MAC  =	-L $(RL_LIB)

ifeq ($(detected_OS), Linux)
 RL_PATH	+=	/usr/local /usr
 RL_INC 	=	$(shell find $(RL_PATH) -type d -name $(RL) | grep "include")
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RL_PATH	+=	/opt ~/.brew /usr/local
 RL_INC 	=	$(shell find $(RL_PATH) -type d -name include $(NL) |grep $(RL))
 RL_LIB 	=	$(shell find $(RL_PATH) -type d -name lib $(NL) |grep $(RL))
 RLFLAGS	=	$(CFLAGS) $(INC_RL_MAC) $(LIB_RL_MAC) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) $(INC_RL_MAC) -c $< -o $(<:.c=.o)
endif

# **************************************************************************** #
#              Rules                                                           #
# **************************************************************************** #

.c.o:
		$(CO_LINE)

all: printtoken printsentence printexpunsenv expandvar t_env test_export \
		hdoc pwd execve echo test_sentence

printtoken: $(LIBFT) $(OBJS_P_TOKEN)
	$(CC) $(OBJS_P_TOKEN) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printtoken

pwd :	$(LIBFT) $(OBJS_PWD)
		$(CC) $(OBJS_PWD) $(LIBFT) -o $@

echo:	$(LIBFT) $(OBJS_ECHO)
	$(CC) $(OBJS_ECHO) $(LIBFT) -o $@

execve: $(LIBFT) $(OBJS_EXECVE)
	cc hello_world.c -o hello_world
	$(CC) $(OBJS_EXECVE) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o $@

printexpunsenv: $(LIBFT) $(OBJS_P_EXP_UNSET_ENV)
	$(CC) $(OBJS_P_EXP_UNSET_ENV) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printexpunsenv

expandvar:	$(LIBFT) $(OBJS_EXPANDVAR)
	$(CC) $(CFLAGS) $(OBJS_EXPANDVAR) $(LIBFT) -o $@

printsentence: $(LIBFT) $(OBJS_P_SENTENCE)
	$(CC) $(OBJS_P_SENTENCE) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printsentence

t_env: $(LIBFT) $(OBJS_T_ENV)
	$(CC) $(CFLAGS) $(OBJS_T_ENV) $(LIBFT) -o $@

test_export: $(LIBFT) $(OBJS_EXPORT)
	$(CC) $(CFLAGS) $(OBJS_EXPORT) $(LIBFT) -o $@

hdoc:	$(LIBFT) $(OBJS_HDOC)
	$(CC) $(OBJS_HDOC) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o hdoc

test_sentence:	$(LIBFT) $(OBJS_SENT)
	$(CC) $(OBJS_SENT) $(LIBFT) -o test_sentence

tkn_to_sentence:	$(LIBFT) $(OBJS_TKN_SENT)
	$(CC) $(OBJS_TKN_SENT) $(LIBFT) -o tkn_to_sentence

clean:
		$(RM) $(OBJS_P_TOKEN) $(OBJS_P_SENTENCE) $(OBJS_P_EXP_UNSET_ENV) $(OBJS_EXPANDVAR)
		$(RM) $(OBJS_EXECVE) $(OBJS_ECHO) $(OBJS_PWD) $(OBJS_T_ENV) $(OBJS_REDIRECTS)
		$(RM) $(OBJS_HDOC) $(OBJS_EXPORT) $(OBJS_SENT) $(OBJS_TKN_SENT)

fclean: clean
		$(RM) printtoken printsentence printexpunsenv expandvar execve echo pwd t_env hello_world \
		$(RM) hdoc test_export test_sentence tkn_to_sentence

re:			fclean all

.PHONY	:	all clean fclean re
