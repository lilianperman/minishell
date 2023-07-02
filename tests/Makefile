# **************************************************************************** #
#                          Minishell Unity Testing
# **************************************************************************** #

# i.e. make tests
# i.e. make

SRCD	=	../srcs
INCD	=	../inc
_SRCS	=	$(shell find $(SRCD) ! -iname "main.c" -type f | grep -E ".+\.c")
_OBJS	=	$(_SRCS:.c=.o)


SRCS 	=	$(shell find . -type f -iname "*.c" ! -path "*/exclude_test/*" | cut -c 3- | sort)
NAME	=	$(SRCS:.c=)
OBJS	=	$(NAME)


# **************************************************************************** #
#    COMPILER AND FLAGS                                                        #
# **************************************************************************** #

CC			=	cc
RM			= 	rm -f
CFLAGS		=	-Wall -Wextra -Werror
MFLAG		=	-C

INC			=	-I ../libft/ -I ../libft/ft_printf/ -I ../inc/
LIB			=	minishell.a

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

RL			=	readline
RLFLAG		= 	-lreadline

detected_OS	=	$(shell uname -s)
RL_TEST		=	if [ -z "$(RL_INC)" ]; then $(RL_MSG) && false; else true ; fi
NL			=	2>/dev/null
TL			=	-type d -name

INC_RL_MAC  =	-I $(RL_INC)
LIB_RL_MAC  =	-L $(RL_LIB)

ifeq ($(detected_OS), Linux)
 RL_PATH	+=	/usr/local /usr
 RL_INC 	=	$(shell find $(RL_PATH) $(TL) $(RL) | grep "include"| head -1)
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RL_PATH	+=	~/.brew /opt /usr/local
 RL_INC 	=	$(shell find $(RL_PATH) $(TL) include $(NL) |grep $(RL)|head -1)
 RL_LIB 	=	$(shell find $(RL_PATH) $(TL) lib $(NL) |grep $(RL)|head -1)
 RLFLAGS	=	$(CFLAGS) $(INC_RL_MAC) $(LIB_RL_MAC) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) $(INC_RL_MAC) -c $< -o $(<:.c=.o)
endif

# **************************************************************************** #
#              Rules                                                           #
# **************************************************************************** #

all: init $(OBJS) test

$(OBJS): %: %.c
	@$(CO_LINE)
	@$(CC) $(CFLAGS) $(<:.c=.o) $(LIB) -L $(RL_INC) $(RLFLAG) \
		-o $@.out; ./$@.out > $@.log 2>&1   \
		&& (echo "$(grn)[OK]    $(wht)$@$(rst)")       \
		|| (echo "$(red)[KO]    $(wht)$@$(rst)" && touch .errl)
	@rm -f $@.o $@.out

init:
	@$(CHK_ERR)
	@echo && echo "$(ora) Minishell Unity Testing$(rst)" && echo
	@make -C .. VERBOSE=0
	@rm -rf minishell.a
	@cp ../libft/libft.a minishell.a
	@ar rcs minishell.a $(_OBJS)

test:
	@echo && echo "$(ora) Log Files $(rst)" && echo
	@for file in *.log; \
		do echo "$(pnk)$$file:$(rst)" \
		&& cat $$file && echo; \
		done
	@rm -rf logs minishell.a && mkdir -p logs && mv *.log logs/
	@echo && if [ -f ".errl" ]; \
		then rm .errl; echo "$(red)\c"; false; \
		else echo "$(grn)make: *** [$@] SUCCESS! $(rst)"; fi

tests: all

clean:
	@rm -rf logs/

.PHONY: test, tests, init, clean

CHK_ERR =	if [ -f ".errl" ]; then rm .errl; fi

# **************************************************************************** #
#                           Visuals and Messages
# **************************************************************************** #

ok:=✓
ko:=✗
ck:=・

s:=\033[0
red:=$s31m
grn:=$s32m
yel:=$s33m
blu:=$s34m
pnk:=$s35m
cya:=$s36m
wht:=$s37m
rst:=$s00m
ora:=$s38;2;255;153;0m
clr:=$s2K
lup:=$s1A
bld:=$s1m

spin[0]="⠁"
spin[1]="⠃"
spin[2]="⠇"
spin[3]="⠧"
spin[4]="⠷"
spin[5]="⠿"
spin[6]="⠷"
spin[7]="⠧"
spin[8]="⠇"
spin[9]="⠃"

# **************************************************************************** #
