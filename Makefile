SRCS = src/ft_strlen.s src/ft_strcpy.s src/ft_strcmp.s src/ft_write.s src/ft_read.s src/ft_strdup.s
CSRCS = main.c

BSRCS = src/ft_atoi_base.s src/ft_list_push_front.s src/ft_list_size.s src/ft_list_sort.s src/ft_list_remove_if.s
BCSRCS = bonus.c

OBJS_ASM = ${SRCS:.s=.o}
OBJS_C = ${CSRCS:.c=.o}
OBJS_BASM = ${BSRCS:.s=.o}
OBJS_BC = ${BCSRCS:.c=.o}

ASM_FLAGS = -f macho64
CFLAGS = -Wall -Wextra -Werror

LIB_ASM = libasm.a

NAME = libasm

INCLUDES = -I ./includes

all : ${NAME}

bonus:	fclean lib_bonus ${OBJS_BC}
		gcc ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJS_BC} ${LIB_ASM}

%.o:	%.s
		nasm ${ASM_FLAGS} $< -o $@

%.o:	%.c
		gcc -o $@ -c ${INCLUDES} $< ${CFLAGS}

lib :	${OBJS_ASM}
		ar rcs ${LIB_ASM} ${OBJS_ASM}

lib_bonus:	${OBJS_BASM}
			ar rcs ${LIB_ASM} ${OBJS_BASM}

${NAME}:	lib ${OBJS_C}
			gcc ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJS_C} ${LIB_ASM}

clean:
		rm -rf ${OBJS_ASM} ${OBJS_C} ${OBJS_BASM} ${OBJS_BC}

fclean:	clean
		rm -rf ${NAME} ${LIB_ASM}

re:		fclean all
