NAME		= checker
ifdef BONUS
	NAME 	= checker_bonus
endif

CFLAGS		= -Wno-format -Iincludes

# Sources & Objects
SRCS		=	srcs/main.c
ifdef BONUS
	SRCS	=	srcs/bonus.c
endif

OBJS 		:=	$(addsuffix .o, $(basename $(SRCS)))

# Rules
all:		libasm  $(NAME)

bonus:
	@make BONUS=1

libasm:
	@make -C libasm/

$(NAME): libasm/libasm.a $(OBJS) 
	$(CC) $(CCFLAGS) $(OBJS) libasm/libasm.a -o $(NAME)

re:	fclean all

clean:
ifndef BONUS
	@make BONUS=1 clean
	make -C libasm/ clean
endif
	rm -f $(OBJS)


fclean: clean
ifndef BONUS
	@make BONUS=1 fclean
	make -C libasm/ fclean
endif
	rm -f $(NAME)

.PHONY: all clean fclean re libasm
