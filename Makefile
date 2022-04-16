NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CFALGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):$(OBJS)
	  ar -cr $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	cc $(CFALGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all
