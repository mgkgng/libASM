AS			= nasm

NAME		= libasm.a

ASFLAGS 	= -fmacho64

# Sources & Objects
SRCS		=	ft_read.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_strdup.s \
				ft_strlen.s \
				ft_write.s
SRCS_BONUS	=	ft_atoi_base_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_size_bonus.s \
				ft_list_remove_if_bonus.s \
				ft_list_sort_bonus.s

OBJS 		:=	$(addsuffix .o, $(basename $(SRCS)))
OBJS_BONUS	:=  $(addsuffix .o, $(basename $(SRCS_BONUS)))

ifdef BONUS
	OBJS	+=	$(OBJS_BONUS)
endif

# Rules
all:		$(NAME)

bonus:
	@make BONUS=1

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

re:	fclean all

clean:
	rm -f $(OBJS_BONUS)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
