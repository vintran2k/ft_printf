SRCS		= 	ft_printf.c					\
				utils.c						\
				utils2.c					\
				utils3.c					\
				get_args.c					\
				init_struct.c				\
				init_struct2.c				\
				diux_flag.c					\
				diux_flag2.c				\
				c_flag.c					\
				c_flag2.c					\
				s_flag.c					\
				s_flag2.c					\
				p_flag.c					\
				p_flag2.c					\
				print_flags.c				\
		
OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
