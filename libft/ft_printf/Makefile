SRCS		= ft_printf.c ft_putchar_pf.c ft_putnbr_pf.c ft_putstr_pf.c \
			  ft_putnbru_pf.c ft_puthex_pf.c ft_puthexx_pf.c ft_puthexp_pf.c \
			  ft_spec_conversion.c 

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= cc

LIBC		= ar rcs

LIBR		= ranlib

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

MLIBFT		= cp ../libft.a $(NAME)

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MLIBFT)
			$(LIBC) $(NAME) $(OBJS)
			$(LIBR) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

