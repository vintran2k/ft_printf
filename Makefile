SRCS		= 	ft_printf.c					\
				utils.c						\
				utils2.c					\
				utils3.c					\
				get_args.c					\
				init_struct.c				\
				d_i_u_x_X_flag.c			\
				d_i_u_x_X_flag2.c			\
				c_flag.c					\
				c_flag2.c					\
				s_flag.c					\
				s_flag2.c					\
				p_flag.c					\
				print_flags.c				\
		
OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${BOBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
