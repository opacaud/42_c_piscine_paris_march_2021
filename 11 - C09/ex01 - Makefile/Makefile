SRC_DIR = srcs/

SRCS = ${SRC_DIR}ft_putchar.c ${SRC_DIR}ft_swap.c ${SRC_DIR}ft_putstr.c ${SRC_DIR}ft_strlen.c ${SRC_DIR}ft_strcmp.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}: 	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY :	all clean fclean re
