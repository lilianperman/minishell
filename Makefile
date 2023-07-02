# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

SRCD		=	srcs
INCD		=	inc
TSTD		=	tests

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC			=	-I ./libft/ -I ./libft/ft_printf/ -I ./inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS		=	$(shell find $(SRCD) ! -path $(SRCD) -type f | grep -E ".+\.c")
OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#    LIBFT                                                                     #
# **************************************************************************** #

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	$(LFT)/$(LFT).a

# **************************************************************************** #
#    COMPILER AND FLAGS                                                        #
# **************************************************************************** #

CC			=	cc

RM			= 	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

RLFLAG		= 	-lreadline

MFLAG		=	-C

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

RL			=	readline

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
#    Mandatory rules                                                           #
# **************************************************************************** #

.c.o:
			$(RL_TEST)
			${AT} $(CO_LINE) ${BLK}

all:		$(NAME)

$(LIBFT):
			${AT} $(MAKE) $(CLFT) ${BLK}
			${COMPILE}


$(NAME):	$(LIBFT) $(OBJS)
			${AT} $(CC) $(OBJS) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o $(NAME) ${BLK}
			${COMPILE}
clean:
			${AT} $(RM) $(OBJS) ${BLK}
			${AT} $(MAKE) $@ $(CLFT) ${BLK}
			$(RM_OBJS)

fclean:		clean
			${AT} $(RM) $(NAME) ${BLK}
			${AT} $(MAKE) $@ $(CLFT) ${BLK}
			$(RM_LIBS)

re:			fclean all


.PHONY:		all clean fclean re

# **************************************************************************** #
#                           Norminette
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} echo "$(pnk)\c"; \
	norminette ${SRCS} ${INCD} | grep "Error" || \
	echo "$(grn)$(ok)	Norminette		OK!" ${BLK}

# **************************************************************************** #
#                           Tests
# **************************************************************************** #

.PHONY: tests
tests:
	if [ -f $(TSTD)/Makefile ]; then \
		$(MAKE) $@ $(MFLAG) $(TSTD); \
	else \
		echo "$(wht) Testing environment is not set \c"; \
		echo "$(ora)($(TSTD)/)$(rst)"; \
		false; \
	fi

# **************************************************************************** #
#                           Helper
# **************************************************************************** #

.PHONY: help
help:
	@$(PRT) "$(wht) make \c"
	@$(PRT) "$(wht) [all | clean | fclean | re | tests |\c"
	@$(PRT) "$(pnk) norm$(rst)]\c"
	@$(PRT) "$(cya) [VERBOSE=0..4]"
	@$(PRT) "$(wht) "
	@$(PRT) "$(cya) Verbose levels"
	@$(PRT) "$(wht) # 0: Make will be totaly silenced"
	@$(PRT) "$(grn) # 1: Make will print echos"
	@$(PRT) "$(yel) # 2: Make will not print target commands"
	@$(PRT) "$(ora) # 3: Make will print each command"
	@$(PRT) "$(red) # 4: Make will print all debug info $(rst)"

# **************************************************************************** #
#                          Verbose Check
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print only
# echoes like if VERBOSE was set to 1.

VERBOSE		:= 1

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLK := >/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

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

PRT := echo
_OK := $(grn)$(ok)	Compiled		$(rst)
_CK := $(ora)$(ck)	Creating		$(rst)
_KO := $(red)$(ko)	Removing		$(rst)

COMPILE = ${AT} ${PRT} "${_OK}${grn}${@F}${rst}" ${BLK}
RM_OBJS = ${AT} ${PRT} "$(_KO)$(red)objects$(rst)" ${BLK}
RM_LIBS = ${AT} ${PRT} "$(_KO)$(red)${LFT}.a$(rst)" ${BLK}
RL_MSG  = ${PRT} "$(ora)$(ck)	${RL}${wht} is not installed.${rst}"

# **************************************************************************** #
