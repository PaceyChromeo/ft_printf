NAME = libftprintf.a
SRC = ${addprefix ./srcs/, ft_get_char.c \
							ft_get_hexa.c \
							ft_get_int.c \
							ft_get_percent.c \
							ft_get_pointer.c \
							ft_get_str.c \
							ft_get_uint.c \
							ft_printf.c \
							ft_uitoa.c \
							ft_ullitoa_base.c \
							ft_get_flags.c \
							ft_treat_flags.c \
							ft_treat_width.c \
							ft_treat_prec.c \
							ft_miscelleanous.c}
OBJ = ${SRC:.c=.o}
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${MAKE} all -C ./libft
	cp libft/libft.a ${NAME}
	ar rcs ${NAME} ${OBJ}
all: ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} $(OBJ)

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} $(NAME)

re: fclean ${NAME} 

.PHONY: libftprintf.a all clean fclean re
